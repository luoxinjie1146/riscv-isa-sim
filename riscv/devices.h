#ifndef _RISCV_DEVICES_H
#define _RISCV_DEVICES_H

#include "decode.h"
#include "mmio_plugin.h"
#include <cstdlib>
#include <string>
#include <map>
#include <vector>

class processor_t;

class abstract_device_t {
 public:
  virtual bool load(reg_t addr, size_t len, uint8_t* bytes) = 0; //lxj// 读取数据至bytes
  virtual bool store(reg_t addr, size_t len, const uint8_t* bytes) = 0;
  virtual ~abstract_device_t() {}
};

class bus_t : public abstract_device_t {
 public:
  bool load(reg_t addr, size_t len, uint8_t* bytes); //lxj// 寻找含有addr的设备，并读取数据至bytes
  bool store(reg_t addr, size_t len, const uint8_t* bytes);
  void add_device(reg_t addr, abstract_device_t* dev); //lxj// 想设备列表中加入设备

  std::pair<reg_t, abstract_device_t*> find_device(reg_t addr); //lxj// 查找最后一个不大于addr的设备

 private:
  std::map<reg_t, abstract_device_t*> devices;
};

class rom_device_t : public abstract_device_t {
 public:
  rom_device_t(std::vector<char> data);
  bool load(reg_t addr, size_t len, uint8_t* bytes);
  bool store(reg_t addr, size_t len, const uint8_t* bytes);
  const std::vector<char>& contents() { return data; }
 private:
  std::vector<char> data;
};

class mem_t : public abstract_device_t {
 public:
  mem_t(size_t size) : len(size) {
    if (!size)
      throw std::runtime_error("zero bytes of target memory requested");
    data = (char*)calloc(1, size);
    if (!data)
      throw std::runtime_error("couldn't allocate " + std::to_string(size) + " bytes of target memory");
  }
  mem_t(const mem_t& that) = delete;
  ~mem_t() { free(data); }

  bool load(reg_t addr, size_t len, uint8_t* bytes) { return false; }
  bool store(reg_t addr, size_t len, const uint8_t* bytes) { return false; }
  char* contents() { return data; }
  size_t size() { return len; }

 private:
  char* data; //lxj// 存储的值
  size_t len; //lxj// 存储器长度
};

class clint_t : public abstract_device_t {
 public:
  clint_t(std::vector<processor_t*>&);
  bool load(reg_t addr, size_t len, uint8_t* bytes);
  bool store(reg_t addr, size_t len, const uint8_t* bytes);
  size_t size() { return CLINT_SIZE; }
  void increment(reg_t inc);
 private:
  typedef uint64_t mtime_t;
  typedef uint64_t mtimecmp_t;
  typedef uint32_t msip_t;
  std::vector<processor_t*>& procs;
  mtime_t mtime;
  std::vector<mtimecmp_t> mtimecmp;
};

class mmio_plugin_device_t : public abstract_device_t {
 public:
  mmio_plugin_device_t(const std::string& name, const std::string& args); //lxj// 需要先注册MMIO，才能初始化
  virtual ~mmio_plugin_device_t() override;

  virtual bool load(reg_t addr, size_t len, uint8_t* bytes) override;
  virtual bool store(reg_t addr, size_t len, const uint8_t* bytes) override;

 private:
  mmio_plugin_t plugin;
  void* user_data;
};

#endif

#pragma once
#include <rocksdb/db.h>
#include <string>

class Engine {
public:
    explicit Engine(const std::string& path) {
        rocksdb::Options opt;
        opt.create_if_missing = true;
        rocksdb::Status s = rocksdb::DB::Open(opt, path, &db_);
        if (!s.ok()) throw std::runtime_error(s.ToString());
    }
    ~Engine() { delete db_; }

    std::string Get(const std::string& key) const {
        std::string val;
        auto s = db_->Get(rocksdb::ReadOptions(), key, &val);
        return s.ok() ? val : "";
    }
    void Put(const std::string& key, const std::string& val) const {
        db_->Put(rocksdb::WriteOptions(), key, val);
    }
    void Del(const std::string& key) const {
        db_->Delete(rocksdb::WriteOptions(), key);
    }
private:
    rocksdb::DB* db_;
};
#include "mkdir.h"
#include <filesystem>
#include <system_error>

namespace fs = std::filesystem;

MkDirWorker::MkDirWorker(Function& callback, const std::string& path)
    : AsyncWorker(callback), path(path) {};

void MkDirWorker::Execute() {
    std::error_code ec;
    auto success = fs::create_directories(path, ec);
    if (!success && ec) { // if no error code, already exist, nothing to do
        const auto msg = "I wasn\'t able to do that, because: " + ec.message();
        SetError(msg);
    }
};

void MkDirWorker::OnOK() {
    auto msg = "ok! we are good to go with " + path;
    Callback().Call({Env().Undefined(), String::New(Env(), msg)});
};
#include "engine.h"
#include <httplib.h>

int main() {
    Engine db("/tmp/minikv_db");

    httplib::Server svr;
    svr.Get(R"(/(\w+))", [&](const auto& req, auto& res) {
        auto val = db.Get(req.matches[1]);
        if (val.empty()) res.status = 404;
        else res.set_content(val, "text/plain");
    });
    svr.Put(R"(/(\w+))", [&](const auto& req, auto& res) {
        db.Put(req.matches[1], req.body);
        res.set_content("OK", "text/plain");
    });
    svr.Delete(R"(/(\w+))", [&](const auto& req, auto& res) {
        db.Del(req.matches[1]);
        res.set_content("OK", "text/plain");
    });

    std::cout << "Listening on http://0.0.0.0:7777\n";
    svr.listen("0.0.0.0", 7777);
}
#include "server_api.h"

//登录
void User::loginInfo(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback,
                 std::string &&userId,
                 const std::string &password) {
    HttpResponsePtr resp;
    //认证算法，读数据库，验证身份等...
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.user WHERE username = $1 AND password = $2", userId, password);
    try {
        auto r = f.get();
        if (r.size() > 0) {
            LOG_DEBUG << "User " << userId << "登陆成功";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "登录成功";
            ret["token"] = drogon::utils::getUuid(); //生成token
            resp = HttpResponse::newHttpJsonResponse(ret);
        } else {
            LOG_DEBUG << "User " << userId << "尝试登录失败";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "登录失败";
            resp = HttpResponse::newHttpJsonResponse(ret);
        }
        callback(resp);
    }catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//删除设备中心
void User::deleteFacilityCenter(const HttpRequestPtr &req,
                          std::function<void(const HttpResponsePtr &)> &&callback,
                          const std::string &name){
    HttpResponsePtr resp;
    //认证算法，读数据库，验证身份等...
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.facilitycenter_value WHERE name = $1", name);
    try {
        auto r = f.get();
        if (r.size() > 0) {
            clientPtr->execSqlAsyncFuture("DELETE FROM public.facilitycenter_value WHERE name = $1", name);
            LOG_DEBUG << "设备: " << name << "删除成功";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "删除成功";
            resp = HttpResponse::newHttpJsonResponse(ret);
        } else {
            LOG_DEBUG << "设备: " << name << "删除失败，不存在该数据";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "删除失败";
            resp = HttpResponse::newHttpJsonResponse(ret);
        }
        callback(resp);
    }catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}


//删除数据中心
void User::deleteCenterData(const HttpRequestPtr &req,
                                std::function<void(const HttpResponsePtr &)> &&callback,
                                const std::string &name){
    HttpResponsePtr resp;
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.datacenter_value WHERE name = $1", name);
    try {
        auto r = f.get();
        if (r.size() > 0) {
            clientPtr->execSqlAsyncFuture("DELETE FROM public.datacenter_value WHERE name = $1", name);
            LOG_DEBUG << "数据: " << name << "删除成功";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "删除成功";
            resp = HttpResponse::newHttpJsonResponse(ret);
        } else {
            LOG_DEBUG << "数据: " << name << "删除失败，不存在该数据";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "删除失败";
            resp = HttpResponse::newHttpJsonResponse(ret);
        }
        callback(resp);
    }catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//忘记密码
void User::forgetPasswordInfo(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback,
                     std::string &&userId,
                     const std::string &password) {
    HttpResponsePtr resp;
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.user WHERE username = $1", userId);
    try {
        auto r = f.get();
        if (r.size() > 0) {
            clientPtr->execSqlAsyncFuture("update public.user set password=$1 where username=$2", password, userId);
            LOG_DEBUG << "User " << userId << "密码修改成功";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "修改成功";
            resp = HttpResponse::newHttpJsonResponse(ret);
        } else {
            LOG_DEBUG << "User " << userId << "不存在";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "用户不存在";
            resp = HttpResponse::newHttpJsonResponse(ret);
        }
        callback(resp);
    }catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//注册
void User::registerInfo(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback,
                              std::string &&userId,
                              const std::string &password) {
    HttpResponsePtr resp;
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.user WHERE username = $1", userId);
    try {
        auto r = f.get();
        if (r.size() > 0) {
            LOG_DEBUG << "User " << userId << "已存在，无法注册";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "用户名存在";
            resp = HttpResponse::newHttpJsonResponse(ret);
        } else {
            clientPtr->execSqlAsyncFuture("INSERT INTO public.user(username, password)VALUES ($1, $2)", userId,
                                          password);
            LOG_DEBUG << "User " << userId << "注册成功";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "注册成功";
            resp = HttpResponse::newHttpJsonResponse(ret);
        }
        callback(resp);
    }catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//数据中心
void User::getCenterData(const HttpRequestPtr &req,
                         std::function<void(const HttpResponsePtr &)> &&callback,
                         const std::string &name,const std::string &ph,const std::string &temperature,
                         const std::string &humidity,const std::string &N,const std::string &P,const std::string &K,const std::string &date){
    HttpResponsePtr resp;
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.datacenter_value WHERE name = $1", name);
    try {
        auto r = f.get();
        if (r.size() > 0) {
            LOG_DEBUG << "数据：" << name << "已存在，无法添加";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "数据已存在";
            resp = HttpResponse::newHttpJsonResponse(ret);
        } else {
            clientPtr->execSqlAsyncFuture("INSERT INTO public.datacenter_value(name,ph_value,temperature_value,"
                                          "humidity_value,n_value,p_value,k_value,time)VALUES ($1,$2,$3,$4,$5,$6,$7,$8)",
                                          name,ph,temperature,humidity,N,P,K,date);
            LOG_DEBUG << "数据:" << name << "添加成功";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "添加成功";
            resp = HttpResponse::newHttpJsonResponse(ret);
        }
        callback(resp);
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//设备中心
void User::getFacilityData(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback,
                     const std::string &name,const std::string &info,const std::string &number,const std::string &date){
    HttpResponsePtr resp;
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.facilitycenter_value WHERE name = $1", name);
    try {
        auto r = f.get();
        if (r.size() > 0) {
            LOG_DEBUG << "设备：" << name << "已存在，无法添加";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "数据已存在";
            resp = HttpResponse::newHttpJsonResponse(ret);
        } else {
            clientPtr->execSqlAsyncFuture("INSERT INTO public.facilitycenter_value(name,info,number,time)VALUES ($1,$2,$3,$4)",
                                          name,info,number,date);
            LOG_DEBUG << "设备:" << name << "添加成功";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "添加成功";
            resp = HttpResponse::newHttpJsonResponse(ret);
        }
        callback(resp);
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}



//氮含量
void  User::getNitrogenInfo(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.n_value order by id desc limit 5");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            std::reverse(result.begin(), result.end()); // 反转结果数组顺序
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//磷含量
void  User::getPhosphorusInfo(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.p_value order by id desc limit 5");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            std::reverse(result.begin(), result.end()); // 反转结果数组顺序
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//钾含量
void  User::getPotassiumInfo(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.k_value order by id desc limit 5");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            std::reverse(result.begin(), result.end()); // 反转结果数组顺序
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//温度
void  User::getTemperatureInfo(const HttpRequestPtr &req,
                             std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.temperature_value order by id desc limit 5");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            std::reverse(result.begin(), result.end()); // 反转结果数组顺序
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//湿度
void  User::getHumidityInfo(const HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.humidity_value order by id desc limit 5");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            std::reverse(result.begin(), result.end()); // 反转结果数组顺序
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//PH值
void User::getPhValueInfo(const HttpRequestPtr &req,
                          std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.ph_value order by id desc limit 5");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            std::reverse(result.begin(), result.end()); // 反转结果数组顺序
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}



//错误信息
void  User::getErrorInfo(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback){
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.error_value");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["time"] = row["time"].as<std::string>();
                obj["value"] = row["value"].as<std::string>();
                result.append(obj);
            }
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//数据中心
void  User::getDataCenter(const HttpRequestPtr &req,
                         std::function<void(const HttpResponsePtr &)> &&callback){
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.datacenter_value");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["name"] = row["name"].as<std::string>();
                obj["ph_value"] = row["ph_value"].as<std::string>();
                obj["temperature_value"] = row["temperature_value"].as<std::string>();
                obj["humidity_value"] = row["humidity_value"].as<std::string>();
                obj["n_value"] = row["n_value"].as<std::string>();
                obj["p_value"] = row["p_value"].as<std::string>();
                obj["k_value"] = row["k_value"].as<std::string>();
                obj["time"] = row["time"].as<std::string>();
                result.append(obj);
            }
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//设备中心
void  User::getFacilityCenter(const HttpRequestPtr &req,
                         std::function<void(const HttpResponsePtr &)> &&callback){
    Json::Value result;
    auto clientPtr = drogon::app().getDbClient("default");
    auto future = clientPtr->execSqlAsyncFuture("SELECT * FROM public.facilitycenter_value");
    try {
        auto r = future.get();
        if (r.size() > 0) {
            for (const auto& row : r) {
                Json::Value obj;
                obj["name"] = row["name"].as<std::string>();
                obj["info"] = row["info"].as<std::string>();
                obj["number"] = row["number"].as<std::string>();
                obj["time"] = row["time"].as<std::string>();
                result.append(obj);
            }
            auto resp = HttpResponse::newHttpJsonResponse(result);
            callback(resp);
        }
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//编辑数据中心
void User::editCenterData(const HttpRequestPtr &req,
                          std::function<void(const HttpResponsePtr &)> &&callback,
                          const std::string &oldname,
                          const std::string &newname,const std::string &ph,const std::string &temperature,
                          const std::string &humidity,const std::string &N,const std::string &P,const std::string &K,const std::string &date){
    HttpResponsePtr resp;
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.datacenter_value WHERE name = $1", oldname);
    try {
        auto r = f.get();
        if (r.size() > 0) {
            LOG_DEBUG << "数据：" << oldname << "修改成功";
            clientPtr->execSqlAsyncFuture("UPDATE public.datacenter_value SET name=$1,ph_value=$2,temperature_value=$3,humidity_value=$4,n_value=$5,p_value=$6,k_value=$7,time=$8 WHERE name = $9",
                                          newname,ph,temperature,humidity,N,P,K,date,oldname);
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "修改成功";
            resp = HttpResponse::newHttpJsonResponse(ret);
        } else {
            LOG_DEBUG << "数据:" << oldname << "修改失败";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "修改失败";
            resp = HttpResponse::newHttpJsonResponse(ret);
        }
        callback(resp);
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//编辑设备中心
void User::editFacilityCenter(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback,
                              const std::string &oldname,
                              const std::string &newname,const std::string &info,const std::string &num,const std::string &date){
    HttpResponsePtr resp;
    auto clientPtr = drogon::app().getDbClient("default");
    auto f = clientPtr->execSqlAsyncFuture("SELECT * FROM public.facilitycenter_value WHERE name = $1", oldname);
    try {
        auto r = f.get();
        if (r.size() > 0) {
            LOG_DEBUG << "设备：" << oldname << "修改成功";
            clientPtr->execSqlAsyncFuture("UPDATE public.facilitycenter_value SET name=$1,info=$2,number=$3,time=$4 WHERE name = $5",
                                          newname,info,num,date,oldname);
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "修改成功";
            resp = HttpResponse::newHttpJsonResponse(ret);
        } else {
            LOG_DEBUG << "设备:" << oldname << "修改失败";
            Json::Value ret;
            ret["result"] = "ok";
            ret["data"] = "修改失败";
            resp = HttpResponse::newHttpJsonResponse(ret);
        }
        callback(resp);
    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//获取PH、温度、湿度
void User::getPH(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback) {
    Json::Value ret;
    ret["result"] = "success";
    auto res = HttpResponse::newHttpJsonResponse(ret);
    auto clientPtr = drogon::app().getDbClient("default");
    try {
        auto json = req->getJsonObject();

        // 解析客户端发送过来的JSON数据
        auto moisture = json->get("moisture", 0.0).asFloat();
        auto temperature = json->get("temperature", 0.0).asFloat();
        auto ph = json->get("ph", 0.0).asFloat();
        // 获取当前系统时间
        time_t now = time(nullptr);
        char timeStr[32];
        strftime(timeStr, sizeof(timeStr), "%H:%M:%S", localtime(&now));

        clientPtr->execSqlAsyncFuture("INSERT INTO public.ph_value(time, value,flag)VALUES ($1, $2,1)", timeStr,ph);

        clientPtr->execSqlAsyncFuture("INSERT INTO public.temperature_value(time, value,flag)VALUES ($1, $2,1)", timeStr,temperature);

        clientPtr->execSqlAsyncFuture("INSERT INTO public.humidity_value(time, value,flag)VALUES ($1, $2,1)", timeStr,moisture);

    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

//获取NPK
void User::getNPK(const HttpRequestPtr &req,
            std::function<void(const HttpResponsePtr &)> &&callback){
    Json::Value ret;
    ret["result"] = "success";
    auto res = HttpResponse::newHttpJsonResponse(ret);
    auto clientPtr = drogon::app().getDbClient("default");
    try {
        auto json = req->getJsonObject();

        // 解析客户端发送过来的JSON数据
        auto nitrogen = json->get("nitrogen", 0.0).asFloat();
        auto phosphorus = json->get("phosphorus", 0.0).asFloat();
        auto potassium = json->get("potassium", 0.0).asFloat();
        // 获取当前系统时间
        time_t now = time(nullptr);
        char timeStr[32];
        strftime(timeStr, sizeof(timeStr), "%H:%M:%S", localtime(&now));

        clientPtr->execSqlAsyncFuture("INSERT INTO public.n_value(time, value,flag)VALUES ($1, $2,1)", timeStr,nitrogen);

        clientPtr->execSqlAsyncFuture("INSERT INTO public.p_value(time, value,flag)VALUES ($1, $2,1)", timeStr,phosphorus);

        clientPtr->execSqlAsyncFuture("INSERT INTO public.k_value(time, value,flag)VALUES ($1, $2,1)", timeStr,potassium);

    } catch (const std::exception& e) {
        LOG_ERROR << e.what();
    }
}

/**
* helloworld API generated from helloworld.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "HelloworldApi.h"
#include "HelloworldApiImpl.h"

using namespace polycube::service::model;
using namespace polycube::service::api::HelloworldApiImpl;

#ifdef __cplusplus
extern "C" {
#endif

Response create_helloworld_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    HelloworldJsonObject unique_value { request_body };

    unique_value.setName(unique_name);
    create_helloworld_by_id(unique_name, unique_value);
    return { kCreated, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response create_helloworld_ports_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_portsName;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "ports_name")) {
      unique_portsName = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    PortsJsonObject unique_value { request_body };

    unique_value.setName(unique_portsName);
    create_helloworld_ports_by_id(unique_name, unique_portsName, unique_value);
    return { kCreated, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response create_helloworld_ports_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  // Getting the body param
  std::vector<PortsJsonObject> unique_value;

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    std::vector<PortsJsonObject> unique_value;
    for (auto &j : request_body) {
      PortsJsonObject a { j };
      unique_value.push_back(a);
    }
    create_helloworld_ports_list_by_id(unique_name, unique_value);
    return { kCreated, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response delete_helloworld_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {
    delete_helloworld_by_id(unique_name);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response delete_helloworld_ports_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_portsName;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "ports_name")) {
      unique_portsName = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    delete_helloworld_ports_by_id(unique_name, unique_portsName);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response delete_helloworld_ports_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {
    delete_helloworld_ports_list_by_id(unique_name);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_helloworld_action_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_helloworld_action_by_id(unique_name);
    nlohmann::json response_body;
    response_body = HelloworldJsonObject::HelloworldActionEnum_to_string(x);
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_helloworld_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_helloworld_by_id(unique_name);
    nlohmann::json response_body;
    response_body = x.toJson();
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_helloworld_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {


  try {

    auto x = read_helloworld_list_by_id();
    nlohmann::json response_body;
    for (auto &i : x) {
      response_body += i.toJson();
    }
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_helloworld_ports_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_portsName;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "ports_name")) {
      unique_portsName = std::string { keys[i].value.string };
      break;
    }
  }


  try {

    auto x = read_helloworld_ports_by_id(unique_name, unique_portsName);
    nlohmann::json response_body;
    response_body = x.toJson();
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response read_helloworld_ports_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ) {
  // Getting the path params
  std::string unique_name { name };

  try {

    auto x = read_helloworld_ports_list_by_id(unique_name);
    nlohmann::json response_body;
    for (auto &i : x) {
      response_body += i.toJson();
    }
    return { kOk, ::strdup(response_body.dump().c_str()) };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response replace_helloworld_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    HelloworldJsonObject unique_value { request_body };

    unique_value.setName(unique_name);
    replace_helloworld_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response replace_helloworld_ports_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_portsName;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "ports_name")) {
      unique_portsName = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    PortsJsonObject unique_value { request_body };

    unique_value.setName(unique_portsName);
    replace_helloworld_ports_by_id(unique_name, unique_portsName, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response replace_helloworld_ports_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  // Getting the body param
  std::vector<PortsJsonObject> unique_value;

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    std::vector<PortsJsonObject> unique_value;
    for (auto &j : request_body) {
      PortsJsonObject a { j };
      unique_value.push_back(a);
    }
    replace_helloworld_ports_list_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_helloworld_action_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    HelloworldActionEnum unique_value_ = HelloworldJsonObject::string_to_HelloworldActionEnum(request_body);
    update_helloworld_action_by_id(unique_name, unique_value_);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_helloworld_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    HelloworldJsonObject unique_value { request_body };

    unique_value.setName(unique_name);
    update_helloworld_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_helloworld_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {

  // Getting the body param
  std::vector<HelloworldJsonObject> unique_value;

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    std::vector<HelloworldJsonObject> unique_value;
    for (auto &j : request_body) {
      HelloworldJsonObject a { j };
      unique_value.push_back(a);
    }
    update_helloworld_list_by_id(unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_helloworld_ports_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  std::string unique_portsName;
  for (size_t i = 0; i < num_keys; ++i) {
    if (!strcmp(keys[i].name, "ports_name")) {
      unique_portsName = std::string { keys[i].value.string };
      break;
    }
  }


  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    PortsJsonObject unique_value { request_body };

    unique_value.setName(unique_portsName);
    update_helloworld_ports_by_id(unique_name, unique_portsName, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}

Response update_helloworld_ports_list_by_id_handler(
  const char *name, const Key *keys,
  size_t num_keys ,
  const char *value) {
  // Getting the path params
  std::string unique_name { name };
  // Getting the body param
  std::vector<PortsJsonObject> unique_value;

  try {
    auto request_body = nlohmann::json::parse(std::string { value });
    // Getting the body param
    std::vector<PortsJsonObject> unique_value;
    for (auto &j : request_body) {
      PortsJsonObject a { j };
      unique_value.push_back(a);
    }
    update_helloworld_ports_list_by_id(unique_name, unique_value);
    return { kOk, nullptr };
  } catch(const std::exception &e) {
    return { kGenericError, ::strdup(e.what()) };
  }
}


Response helloworld_list_by_id_help(
  const char *name, const Key *keys, size_t num_keys) {

  nlohmann::json val = read_helloworld_list_by_id_get_list();

  return { kOk, ::strdup(val.dump().c_str()) };
}

Response helloworld_ports_list_by_id_help(
  const char *name, const Key *keys, size_t num_keys) {
  // Getting the path params
  std::string unique_name { name };
  nlohmann::json val = read_helloworld_ports_list_by_id_get_list(unique_name);

  return { kOk, ::strdup(val.dump().c_str()) };
}

#ifdef __cplusplus
}
#endif


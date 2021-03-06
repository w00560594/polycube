/**
* pbforwarder API
* pbforwarder API generated from pbforwarder.yang
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */


#include "PbforwarderApiImpl.h"

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

namespace PbforwarderApiImpl {
namespace {
std::unordered_map<std::string, std::shared_ptr<Pbforwarder>> cubes;
std::mutex cubes_mutex;

std::shared_ptr<Pbforwarder> get_cube(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  auto iter = cubes.find(name);
  if (iter == cubes.end()) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }

  return iter->second;
}

}

void create_pbforwarder_by_id(const std::string &name, const PbforwarderJsonObject &jsonObject) {
  {
    // check if name is valid before creating it
    std::lock_guard<std::mutex> guard(cubes_mutex);
    if (cubes.count(name) != 0) {
      throw std::runtime_error("There is already a cube with name " + name);
    }
  }
  auto ptr = std::make_shared<Pbforwarder>(name, jsonObject);
  std::unordered_map<std::string, std::shared_ptr<Pbforwarder>>::iterator iter;
  bool inserted;

  std::lock_guard<std::mutex> guard(cubes_mutex);
  std::tie(iter, inserted) = cubes.emplace(name, std::move(ptr));

  if (!inserted) {
    throw std::runtime_error("There is already a cube with name " + name);
  }
}

void replace_pbforwarder_by_id(const std::string &name, const PbforwarderJsonObject &bridge){
  throw std::runtime_error("Method not supported!");
}

void delete_pbforwarder_by_id(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  if (cubes.count(name) == 0) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }
  cubes.erase(name);
}

std::vector<PbforwarderJsonObject> read_pbforwarder_list_by_id() {
  std::vector<PbforwarderJsonObject> jsonObject_vect;
  for(auto &i : cubes) {
    auto m = get_cube(i.first);
    jsonObject_vect.push_back(m->toJsonObject());
  }
  return jsonObject_vect;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> read_pbforwarder_list_by_id_get_list() {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  for (auto &x : cubes) {
    nlohmann::fifo_map<std::string, std::string> m;
    m["name"] = x.first;
    r.push_back(std::move(m));
  }
  return r;
}

/**
* @brief   Create ports by ID
*
* Create operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
create_pbforwarder_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto pbforwarder = get_cube(name);

  pbforwarder->addPorts(portsName, value);
}

/**
* @brief   Create ports by ID
*
* Create operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
create_pbforwarder_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  auto pbforwarder = get_cube(name);
  pbforwarder->addPortsList(value);
}

/**
* @brief   Create rules by ID
*
* Create operation of resource: rules*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value rulesbody object
*
* Responses:
*
*/
void
create_pbforwarder_rules_by_id(const std::string &name, const uint32_t &id, const RulesJsonObject &value) {
  auto pbforwarder = get_cube(name);

  pbforwarder->addRules(id, value);
}

/**
* @brief   Create rules by ID
*
* Create operation of resource: rules*
*
* @param[in] name ID of name
* @param[in] value rulesbody object
*
* Responses:
*
*/
void
create_pbforwarder_rules_list_by_id(const std::string &name, const std::vector<RulesJsonObject> &value) {
  auto pbforwarder = get_cube(name);
  pbforwarder->addRulesList(value);
}

/**
* @brief   Delete ports by ID
*
* Delete operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
*
*/
void
delete_pbforwarder_ports_by_id(const std::string &name, const std::string &portsName) {
  auto pbforwarder = get_cube(name);

  pbforwarder->delPorts(portsName);
}

/**
* @brief   Delete ports by ID
*
* Delete operation of resource: ports*
*
* @param[in] name ID of name
*
* Responses:
*
*/
void
delete_pbforwarder_ports_list_by_id(const std::string &name) {
  auto pbforwarder = get_cube(name);
  pbforwarder->delPortsList();
}

/**
* @brief   Delete rules by ID
*
* Delete operation of resource: rules*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
*
*/
void
delete_pbforwarder_rules_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);

  pbforwarder->delRules(id);
}

/**
* @brief   Delete rules by ID
*
* Delete operation of resource: rules*
*
* @param[in] name ID of name
*
* Responses:
*
*/
void
delete_pbforwarder_rules_list_by_id(const std::string &name) {
  auto pbforwarder = get_cube(name);
  pbforwarder->delRulesList();
}

/**
* @brief   Read pbforwarder by ID
*
* Read operation of resource: pbforwarder*
*
* @param[in] name ID of name
*
* Responses:
* PbforwarderJsonObject
*/
PbforwarderJsonObject
read_pbforwarder_by_id(const std::string &name) {
  return get_cube(name)->toJsonObject();

}

/**
* @brief   Read ports by ID
*
* Read operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
* PortsJsonObject
*/
PortsJsonObject
read_pbforwarder_ports_by_id(const std::string &name, const std::string &portsName) {
  auto pbforwarder = get_cube(name);
  return pbforwarder->getPorts(portsName)->toJsonObject();

}

/**
* @brief   Read ports by ID
*
* Read operation of resource: ports*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<PortsJsonObject>
*/
std::vector<PortsJsonObject>
read_pbforwarder_ports_list_by_id(const std::string &name) {
  auto pbforwarder = get_cube(name);
  auto &&ports = pbforwarder->getPortsList();
  std::vector<PortsJsonObject> m;
  for(auto &i : ports)
    m.push_back(i->toJsonObject());
  return m;
}

/**
* @brief   Read action by ID
*
* Read operation of resource: action*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
* RulesActionEnum
*/
RulesActionEnum
read_pbforwarder_rules_action_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);
  return rules->getAction();

}

/**
* @brief   Read rules by ID
*
* Read operation of resource: rules*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
* RulesJsonObject
*/
RulesJsonObject
read_pbforwarder_rules_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);
  return pbforwarder->getRules(id)->toJsonObject();

}

/**
* @brief   Read dst_ip by ID
*
* Read operation of resource: dst_ip*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_pbforwarder_rules_dst_ip_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);
  return rules->getDstIp();

}

/**
* @brief   Read dst_mac by ID
*
* Read operation of resource: dst_mac*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_pbforwarder_rules_dst_mac_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);
  return rules->getDstMac();

}

/**
* @brief   Read dst_port by ID
*
* Read operation of resource: dst_port*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
* uint16_t
*/
uint16_t
read_pbforwarder_rules_dst_port_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);
  return rules->getDstPort();

}

/**
* @brief   Read in_port by ID
*
* Read operation of resource: in_port*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_pbforwarder_rules_in_port_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);
  return rules->getInPort();

}

/**
* @brief   Read l4_proto by ID
*
* Read operation of resource: l4_proto*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
* RulesL4ProtoEnum
*/
RulesL4ProtoEnum
read_pbforwarder_rules_l4_proto_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);
  return rules->getL4Proto();

}

/**
* @brief   Read rules by ID
*
* Read operation of resource: rules*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<RulesJsonObject>
*/
std::vector<RulesJsonObject>
read_pbforwarder_rules_list_by_id(const std::string &name) {
  auto pbforwarder = get_cube(name);
  auto &&rules = pbforwarder->getRulesList();
  std::vector<RulesJsonObject> m;
  for(auto &i : rules)
    m.push_back(i->toJsonObject());
  return m;
}

/**
* @brief   Read out_port by ID
*
* Read operation of resource: out_port*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_pbforwarder_rules_out_port_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);
  return rules->getOutPort();

}

/**
* @brief   Read src_ip by ID
*
* Read operation of resource: src_ip*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_pbforwarder_rules_src_ip_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);
  return rules->getSrcIp();

}

/**
* @brief   Read src_mac by ID
*
* Read operation of resource: src_mac*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
* std::string
*/
std::string
read_pbforwarder_rules_src_mac_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);
  return rules->getSrcMac();

}

/**
* @brief   Read src_port by ID
*
* Read operation of resource: src_port*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
* uint16_t
*/
uint16_t
read_pbforwarder_rules_src_port_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);
  return rules->getSrcPort();

}

/**
* @brief   Read vlan by ID
*
* Read operation of resource: vlan*
*
* @param[in] name ID of name
* @param[in] id ID of id
*
* Responses:
* uint32_t
*/
uint32_t
read_pbforwarder_rules_vlan_by_id(const std::string &name, const uint32_t &id) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);
  return rules->getVlan();

}

/**
* @brief   Replace ports by ID
*
* Replace operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
replace_pbforwarder_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto pbforwarder = get_cube(name);

  pbforwarder->replacePorts(portsName, value);
}

/**
* @brief   Replace ports by ID
*
* Replace operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
replace_pbforwarder_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Replace rules by ID
*
* Replace operation of resource: rules*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value rulesbody object
*
* Responses:
*
*/
void
replace_pbforwarder_rules_by_id(const std::string &name, const uint32_t &id, const RulesJsonObject &value) {
  auto pbforwarder = get_cube(name);

  pbforwarder->replaceRules(id, value);
}

/**
* @brief   Replace rules by ID
*
* Replace operation of resource: rules*
*
* @param[in] name ID of name
* @param[in] value rulesbody object
*
* Responses:
*
*/
void
replace_pbforwarder_rules_list_by_id(const std::string &name, const std::vector<RulesJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update pbforwarder by ID
*
* Update operation of resource: pbforwarder*
*
* @param[in] name ID of name
* @param[in] value pbforwarderbody object
*
* Responses:
*
*/
void
update_pbforwarder_by_id(const std::string &name, const PbforwarderJsonObject &value) {
  auto pbforwarder = get_cube(name);

  pbforwarder->update(value);
}

/**
* @brief   Update pbforwarder by ID
*
* Update operation of resource: pbforwarder*
*
* @param[in] value pbforwarderbody object
*
* Responses:
*
*/
void
update_pbforwarder_list_by_id(const std::vector<PbforwarderJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
update_pbforwarder_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto pbforwarder = get_cube(name);
  auto ports = pbforwarder->getPorts(portsName);

  ports->update(value);
}

/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
update_pbforwarder_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update action by ID
*
* Update operation of resource: action*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value Action associated to the rule(i.e., DROP, SLOWPATH, or FORWARD; default: DROP)
*
* Responses:
*
*/
void
update_pbforwarder_rules_action_by_id(const std::string &name, const uint32_t &id, const RulesActionEnum &value) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);

  rules->setAction(value);
}

/**
* @brief   Update rules by ID
*
* Update operation of resource: rules*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value rulesbody object
*
* Responses:
*
*/
void
update_pbforwarder_rules_by_id(const std::string &name, const uint32_t &id, const RulesJsonObject &value) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);

  rules->update(value);
}

/**
* @brief   Update dst_ip by ID
*
* Update operation of resource: dst_ip*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value Destination IP Address in the form AA.BB.CC.DD
*
* Responses:
*
*/
void
update_pbforwarder_rules_dst_ip_by_id(const std::string &name, const uint32_t &id, const std::string &value) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);

  rules->setDstIp(value);
}

/**
* @brief   Update dst_mac by ID
*
* Update operation of resource: dst_mac*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value Destination MAC Address in the form AA:BB:CC:DD:EE:FF
*
* Responses:
*
*/
void
update_pbforwarder_rules_dst_mac_by_id(const std::string &name, const uint32_t &id, const std::string &value) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);

  rules->setDstMac(value);
}

/**
* @brief   Update dst_port by ID
*
* Update operation of resource: dst_port*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value Destination L4 Port
*
* Responses:
*
*/
void
update_pbforwarder_rules_dst_port_by_id(const std::string &name, const uint32_t &id, const uint16_t &value) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);

  rules->setDstPort(value);
}

/**
* @brief   Update in_port by ID
*
* Update operation of resource: in_port*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value Ingress port
*
* Responses:
*
*/
void
update_pbforwarder_rules_in_port_by_id(const std::string &name, const uint32_t &id, const std::string &value) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);

  rules->setInPort(value);
}

/**
* @brief   Update l4_proto by ID
*
* Update operation of resource: l4_proto*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value Level 4 Protocol (i.e. UDP, TCP)
*
* Responses:
*
*/
void
update_pbforwarder_rules_l4_proto_by_id(const std::string &name, const uint32_t &id, const RulesL4ProtoEnum &value) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);

  rules->setL4Proto(value);
}

/**
* @brief   Update rules by ID
*
* Update operation of resource: rules*
*
* @param[in] name ID of name
* @param[in] value rulesbody object
*
* Responses:
*
*/
void
update_pbforwarder_rules_list_by_id(const std::string &name, const std::vector<RulesJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}

/**
* @brief   Update out_port by ID
*
* Update operation of resource: out_port*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value Output port (used only when action is FORWARD)
*
* Responses:
*
*/
void
update_pbforwarder_rules_out_port_by_id(const std::string &name, const uint32_t &id, const std::string &value) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);

  rules->setOutPort(value);
}

/**
* @brief   Update src_ip by ID
*
* Update operation of resource: src_ip*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value Source IP Address in the form AA.BB.CC.DD
*
* Responses:
*
*/
void
update_pbforwarder_rules_src_ip_by_id(const std::string &name, const uint32_t &id, const std::string &value) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);

  rules->setSrcIp(value);
}

/**
* @brief   Update src_mac by ID
*
* Update operation of resource: src_mac*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value Source MAC Address in the form AA:BB:CC:DD:EE:FF
*
* Responses:
*
*/
void
update_pbforwarder_rules_src_mac_by_id(const std::string &name, const uint32_t &id, const std::string &value) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);

  rules->setSrcMac(value);
}

/**
* @brief   Update src_port by ID
*
* Update operation of resource: src_port*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value Source L4 Port
*
* Responses:
*
*/
void
update_pbforwarder_rules_src_port_by_id(const std::string &name, const uint32_t &id, const uint16_t &value) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);

  rules->setSrcPort(value);
}

/**
* @brief   Update vlan by ID
*
* Update operation of resource: vlan*
*
* @param[in] name ID of name
* @param[in] id ID of id
* @param[in] value VLAN Identifier
*
* Responses:
*
*/
void
update_pbforwarder_rules_vlan_by_id(const std::string &name, const uint32_t &id, const uint32_t &value) {
  auto pbforwarder = get_cube(name);
  auto rules = pbforwarder->getRules(id);

  rules->setVlan(value);
}



/*
 * help related
 */

std::vector<nlohmann::fifo_map<std::string, std::string>> read_pbforwarder_ports_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&pbforwarder = get_cube(name);

  auto &&ports = pbforwarder->getPortsList();
  for(auto &i : ports) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["name"] = i->getName();

    r.push_back(keys);
  }
  return r;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> read_pbforwarder_rules_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&pbforwarder = get_cube(name);

  auto &&rules = pbforwarder->getRulesList();
  for(auto &i : rules) {
    nlohmann::fifo_map<std::string, std::string> keys;

    keys["id"] = std::to_string(i->getId());

    r.push_back(keys);
  }
  return r;
}


}

}
}
}
}


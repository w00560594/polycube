/**
* firewall API generated from firewall.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */



#include "ChainInsertOutputJsonObject.h"
#include <regex>

namespace polycube {
namespace service {
namespace model {

ChainInsertOutputJsonObject::ChainInsertOutputJsonObject() {
  m_idIsSet = false;
}

ChainInsertOutputJsonObject::ChainInsertOutputJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_idIsSet = false;


  if (val.count("id")) {
    setId(val.at("id").get<uint32_t>());
  }
}

nlohmann::json ChainInsertOutputJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_idIsSet) {
    val["id"] = m_id;
  }

  return val;
}

uint32_t ChainInsertOutputJsonObject::getId() const {
  return m_id;
}

void ChainInsertOutputJsonObject::setId(uint32_t value) {
  m_id = value;
  m_idIsSet = true;
}

bool ChainInsertOutputJsonObject::idIsSet() const {
  return m_idIsSet;
}

void ChainInsertOutputJsonObject::unsetId() {
  m_idIsSet = false;
}


}
}
}

// Copyright 2015 TIER IV, Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef OPENSCENARIO_INTERPRETER__SYNTAX__RELATIVE_OBJECT_POSITION_HPP_
#define OPENSCENARIO_INTERPRETER__SYNTAX__RELATIVE_OBJECT_POSITION_HPP_

#include <openscenario_interpreter/scope.hpp>
#include <openscenario_interpreter/simulator_core.hpp>
#include <openscenario_interpreter/syntax/double.hpp>
#include <openscenario_interpreter/syntax/entity_ref.hpp>
#include <openscenario_interpreter/syntax/orientation.hpp>
#include <pugixml.hpp>
#include <traffic_simulator_msgs/msg/lanelet_pose.hpp>

namespace openscenario_interpreter
{
inline namespace syntax
{
/* ---- RelativeObjectPosition 1.2 ---------------------------------------------
 *
 *  <xsd:complexType name="RelativeObjectPosition">
 *    <xsd:all>
 *      <xsd:element name="Orientation" type="Orientation" minOccurs="0"/>
 *    </xsd:all>
 *    <xsd:attribute name="entityRef" type="String" use="required"/>
 *    <xsd:attribute name="dx" type="Double" use="required"/>
 *    <xsd:attribute name="dy" type="Double" use="required"/>
 *    <xsd:attribute name="dz" type="Double" use="optional"/>
 *  </xsd:complexType>
 *
 * -------------------------------------------------------------------------- */
struct RelativeObjectPosition : private SimulatorCore::CoordinateSystemConversion
{
  const Orientation orientation;

  const String entity_ref;

  const Double dx, dy, dz;

  explicit RelativeObjectPosition(const pugi::xml_node &, Scope &);

  operator geometry_msgs::msg::Point() const;

  explicit operator NativeLanePosition() const;

  explicit operator NativeWorldPosition() const;
};
}  // namespace syntax
}  // namespace openscenario_interpreter

#endif  // OPENSCENARIO_INTERPRETER__SYNTAX__RELATIVE_OBJECT_POSITION_HPP_

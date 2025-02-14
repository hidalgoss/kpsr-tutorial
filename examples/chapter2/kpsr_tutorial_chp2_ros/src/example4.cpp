/****************************************************************************
 *
 *                           Klepsydra Core Modules
 *              Copyright (C) 2019-2020  Klepsydra Technologies GmbH
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/
#include <iostream>

#include <kpsr_ros_core/ros_env.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "kpsr_ros_environment");
    ros::NodeHandle nodeHandle;

    kpsr::ros_mdlw::RosEnv environment(&nodeHandle);

    std::string rosversion;
    environment.getPropertyString("rosversion", rosversion);

    std::cout << " The ros version is " << rosversion << std::endl;

    float paramFloat(1.5f);
    environment.setPropertyFloat("paramFloat", paramFloat);
    return 0;
}

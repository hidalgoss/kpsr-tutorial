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

#include "sum_vector_data.h"

#include <klepsydra/high_performance/event_loop_middleware_provider.h>

int main()
{
    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;

    kpsr::high_performance::EventLoopMiddlewareProvider<16> eventloop(nullptr);
    kpsr::Publisher<std::vector<float>> *vectorPublisher =
        eventloop.getPublisher<std::vector<float>>("vector", 0, nullptr, nullptr);

    eventloop.start();

    {
        SumVectorData sumVectorData(eventloop.getSubscriber<std::vector<float>>("vector"),
                                    eventloop.getPublisher<float>("sum", 0, nullptr, nullptr));

        eventloop.getSubscriber<float>("sum")->registerListener("sum", [](const float &message) {
            std::cout << "Sum received: " << message << std::endl;
            std::cout << "Eventeloop (subscriber) ID thread : " << std::this_thread::get_id()
                      << std::endl;
        });

        std::thread vectorPublisherThread([&vectorPublisher]() {
            for (int i = 0; i < 100; i++) {
                std::vector<float> vector(10);
                for (int j = 0; j < 10; j++) {
                    vector[j] = static_cast<float>(j);
                }
                vectorPublisher->publish(vector);
                std::this_thread::sleep_for(std::chrono::milliseconds(5));
                std::cout << "vectorPublisherThread thread ID: " << std::this_thread::get_id()
                          << std::endl;
            }
        });

        vectorPublisherThread.join();
    }

    eventloop.stop();
}

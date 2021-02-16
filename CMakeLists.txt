cmake_minimum_required(VERSION 3.1)
project(RType)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(.)
include_directories(./source)
include_directories(./source/ECS)
include_directories(./source/ECS/Systems)
include_directories(./source/ECS/Managers)
include_directories(./source/ECS/Components)
include_directories(./source/ECS/Network)
include_directories(./source/Prefabs)
include_directories(./source/Server)

set(CLIENT_FILES    main.cpp
                    ./source/Server/Player.cpp
                    ./source/Server/SafeQueue.cpp
                    ./source/ECS/Managers/EntityManager.cpp
                    ./source/ECS/Managers/SystemManager.cpp
                    ./source/ECS/Systems/Coordinator.cpp
                    ./source/ECS/Systems/ShapeRenderSystem.cpp
                    ./source/ECS/Systems/InputSystem.cpp
                    ./source/ECS/Systems/AnimationSystem.cpp
                    ./source/ECS/Systems/PhysicsSystem.cpp
                    ./source/ECS/Systems/CollisionSystem.cpp
                    ./source/ECS/Systems/SpriteRenderSystem.cpp
                    ./source/ECS/Systems/ClientPlayerNetworkSystem.cpp
                    ./source/ECS/Network/Network.cpp
                    ./source/ECS/Systems/EnemyNetworkSystem.cpp
                    ./source/ECS/Systems/ClientEnemyNetworkSystem.cpp
                    ./source/ECS/Systems/ClientShootNetworkSystem.cpp
                    ./source/ECS/Systems/ShootSystem.cpp
)

set(SERVER_FILES    ./source/Server/main.cpp 
                    ./source/Server/Core.cpp
                    ./source/Server/Interface.cpp
                    ./source/Server/Player.cpp
                    ./source/Server/Room.cpp
                    ./source/Server/SafeQueue.cpp
                    ./source/Server/Server.cpp
                    ./source/ECS/Managers/EntityManager.cpp
                    ./source/ECS/Managers/SystemManager.cpp
                    ./source/ECS/Systems/Coordinator.cpp
                    ./source/ECS/Systems/ShapeRenderSystem.cpp
                    ./source/ECS/Systems/InputSystem.cpp
                    ./source/ECS/Systems/AnimationSystem.cpp
                    ./source/ECS/Systems/PhysicsSystem.cpp
                    ./source/ECS/Systems/CollisionSystem.cpp
                    ./source/ECS/Systems/SpriteRenderSystem.cpp
                    ./source/ECS/Network/Network.cpp
                    ./source/ECS/Systems/EnemyNetworkSystem.cpp
)

add_executable(r-type_client ${CLIENT_FILES})
add_executable(r-type_server ${SERVER_FILES})
target_link_libraries(r-type_client ${CONAN_LIBS})
target_link_libraries(r-type_server ${CONAN_LIBS})

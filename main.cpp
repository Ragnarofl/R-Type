#include <cstdlib>
#include <iostream>

//Systems
#include "ShapeRenderSystem.hpp"
#include "InputSystem.hpp"
#include "AnimationSystem.hpp"
#include "PhysicsSystem.hpp"
#include "CollisionSystem.hpp"
#include "SpriteRenderSystem.hpp"
#include "ClientPlayerNetworkSystem.hpp"
#include "ClientEnemyNetworkSystem.hpp"
#include "ClientShootNetworkSystem.hpp"
#include "ShootSystem.hpp"

//Prefabs
#include "PF_Enemies_Basic.hpp"
#include "PF_Player.hpp"
#include "PF_FirstBoss.hpp"
#include "PF_BasicEnemyShape.hpp"

#include "Enemy.hpp"
#include "Animation.hpp"

Coordinator gCoordinator;

int main(int argc, char **argv)
{
    if (argc != 2)
        return EXIT_FAILURE;
    Network NetworkInstance(std::atoi(argv[1]));
    // Coordinator Init + Components/Systems Registration  + Game/Window Game settings;
    // --Coordinator Initialize

	gCoordinator.Init();

    // --Components Registration

    int activateSprite = 0;
    gCoordinator.RegisterComponent<PlayerComponent>();
    gCoordinator.RegisterComponent<Enemy>();
    gCoordinator.RegisterComponent<Input>();
    gCoordinator.RegisterComponent<Sprite>();
	gCoordinator.RegisterComponent<Transform>();
	gCoordinator.RegisterComponent<SFMLCircleShape>();
    gCoordinator.RegisterComponent<Animation>();
	gCoordinator.RegisterComponent<Physics>();
	gCoordinator.RegisterComponent<CollisionComponent>();
	gCoordinator.RegisterComponent<ShootComponent>();
    // --Systems Registration

    auto shapeRenderSystem = gCoordinator.RegisterSystem<ShapeRenderSystem>();
	{
		Signature signature;

		signature.set(gCoordinator.GetComponentType<SFMLCircleShape>());
		signature.set(gCoordinator.GetComponentType<Transform>());
        // signature.set(gCoordinator.GetComponentType<PlayerComponent>());
		gCoordinator.SetSystemSignature<ShapeRenderSystem>(signature);
	}

    auto spriteRenderSystem = gCoordinator.RegisterSystem<SpriteRenderSystem>();
	{
		Signature signature;

        signature.set(gCoordinator.GetComponentType<Sprite>());
		signature.set(gCoordinator.GetComponentType<Transform>());
		gCoordinator.SetSystemSignature<SpriteRenderSystem>(signature);
	}


    auto inputSystem = gCoordinator.RegisterSystem<InputSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<PlayerComponent>());
        signature.set(gCoordinator.GetComponentType<Transform>());
        signature.set(gCoordinator.GetComponentType<Input>());
        gCoordinator.SetSystemSignature<InputSystem>(signature);
        
    }
    auto physicsSystem = gCoordinator.RegisterSystem<PhysicsSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Transform>());
        signature.set(gCoordinator.GetComponentType<Physics>());
        signature.set(gCoordinator.GetComponentType<CollisionComponent>());
        gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
        
    }
    auto collisionSystem = gCoordinator.RegisterSystem<CollisionSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Transform>());
        signature.set(gCoordinator.GetComponentType<CollisionComponent>());
        signature.set(gCoordinator.GetComponentType<SFMLCircleShape>());
        gCoordinator.SetSystemSignature<PhysicsSystem>(signature);
        
    }

    auto animationSystem = gCoordinator.RegisterSystem<AnimationSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Animation>());
        signature.set(gCoordinator.GetComponentType<Sprite>());
        gCoordinator.SetSystemSignature<AnimationSystem>(signature);
    }
    auto clientPlayerNetworkSystem = gCoordinator.RegisterSystem<ClientPlayerNetworkSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Transform>());
        signature.set(gCoordinator.GetComponentType<PlayerComponent>());
        gCoordinator.SetSystemSignature<ClientPlayerNetworkSystem>(signature);
    }

    auto clientEnemyNetworkSystem = gCoordinator.RegisterSystem<ClientEnemyNetworkSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Enemy>());
        gCoordinator.SetSystemSignature<ClientEnemyNetworkSystem>(signature);
    }
    auto clientShootNetworkSystem = gCoordinator.RegisterSystem<ClientShootNetworkSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<Transform>());
        signature.set(gCoordinator.GetComponentType<PlayerComponent>());
        signature.set(gCoordinator.GetComponentType<Input>());
        gCoordinator.SetSystemSignature<ClientShootNetworkSystem>(signature);
    }
    auto shootSystem = gCoordinator.RegisterSystem<ShootSystem>();
    {
        Signature signature;
        signature.set(gCoordinator.GetComponentType<PlayerComponent>());
        signature.set(gCoordinator.GetComponentType<Transform>());
        gCoordinator.SetSystemSignature<ShootSystem>(signature);
    }

    // --Window Settings
    sf::ContextSettings Settings;
    Settings.antialiasingLevel = 2;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "R-Type: Ultimate Impact", sf::Style::Default, Settings);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);
    //Game Settings

    sf::Clock Clock;

    //Create Game Prefabs
    // std::cout << "creating prefabs" << std::endl;

    PF_Enemies_Basic EnemiePF;
    // PF_Player PlayerPF;
    // PlayerPF.Create(gCoordinator);

    // std::cout << "boss prefab" << std::endl;
    // PF_FirstBoss bossPF;
    // bossPF.Create(gCoordinator);
    PF_BasicEnemyShape e;

    // usleep(300);
    while (window.isOpen())
    {
        std::string res = NetworkInstance.read();
        // DeltaTime is referring to the spacing between two frames
        sf::Time DeltaTime;
        DeltaTime = Clock.restart();

        if (res.size() > 0)
            std::cout << "Full Server Response: " << res << std::endl;

        //Set Basic Events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
                    // e.Create(gCoordinator, );
                    NetworkInstance.send("102/1", sf::IpAddress(IP_ADDRESS), 10010);

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
                    EnemiePF.Create(gCoordinator, 0,
                        std::vector<sf::Keyboard::Key>{
                            sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Down
                        }
                    );
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
                    NetworkInstance.send("103/RoomPlayerPos", sf::IpAddress(IP_ADDRESS), 10010);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                    NetworkInstance.send("100/CreateRoom", sf::IpAddress(IP_ADDRESS), 10010);
                        EnemiePF.Create(gCoordinator, 0,
                            std::vector<sf::Keyboard::Key>{
                                sf::Keyboard::Right, sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::K
                        }
                    );
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
                    NetworkInstance.send("102/1", sf::IpAddress(IP_ADDRESS), 10010);

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                    EnemiePF.Create(gCoordinator, 2,
                        std::vector<sf::Keyboard::Key>{
		                    sf::Keyboard::H, sf::Keyboard::G, sf::Keyboard::Y
	                    }
                    );
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    NetworkInstance.send("104/1", sf::IpAddress(IP_ADDRESS), 10010);
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        //Clear and Dysplay Window + Update Systems 
        window.clear(sf::Color(51, 51, 77));

        // std::cout << "Updating Systems....." << std::endl;
        collisionSystem->Update(gCoordinator);
        physicsSystem->Update(gCoordinator, DeltaTime.asSeconds());
        inputSystem->Update(gCoordinator, DeltaTime.asSeconds(), NetworkInstance);

        animationSystem->Update(gCoordinator, DeltaTime.asSeconds());
        clientPlayerNetworkSystem->Update(gCoordinator, res);
        clientEnemyNetworkSystem->Update(gCoordinator, res);
        clientShootNetworkSystem->Update(gCoordinator, DeltaTime.asSeconds(), NetworkInstance, res);
        shootSystem->Update(gCoordinator, NetworkInstance);

        shapeRenderSystem->Update(gCoordinator, res);

        spriteRenderSystem->Update(gCoordinator);

        shapeRenderSystem->Draw(gCoordinator, window);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && (activateSprite == 1))
            activateSprite = 0;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && (activateSprite == 0))
            activateSprite = 1;
        if (activateSprite)
            spriteRenderSystem->Draw(gCoordinator, window);

        window.display();
    }
    return 0;
}
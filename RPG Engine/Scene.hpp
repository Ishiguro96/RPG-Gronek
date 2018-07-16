#pragma once

#include "Core/Util/Window.hpp"

#include <SFML/Graphics.hpp>

#include <Box2D/Box2D.h>

#include <iostream>
#include <map>
#include <cmath>

#include "LevelBase.hpp"
#include "SceneNode.hpp"
#include "Core/Entities/Player.hpp"
#include "Core/Entities/EntityBase.hpp"

#include "Core/Util/b2Draw.hpp"

namespace eng {
    enum SceneNodeTypes {PLAYER,
                         TEST_ENTITY
    };


    class Scene{
    public:
        Scene();
        
        void AddSceneNode(const int ID, enum SceneNodeTypes types);
        std::shared_ptr<SceneNode> &GetSceneNode(const int ID);
        
        //Box2D
        void InitializeWorld();
        void WorldLoop();

        //SCENE NODES//
        void InitializeSceneNodes();
        void ClearScene(sf::Color color = sf::Color::Black);
        void HandleSceneNodesInputs();
        void HandleSceneNodesEvents();
        
        //SCENE//
        void UpdateScene();
        void DisplayScene();
    private:
        std::map<int, std::shared_ptr<SceneNode>> _mSceneNodes;
        std::shared_ptr<LevelBase> _mLevel;
        
        //Box2D
        b2World _b2World;
        
        b2BodyDef _b2GroundDef;
        b2Body* _b2Ground;
        b2PolygonShape _b2GroundShape;
        
        b2BodyDef _b2BoxDef;
        b2Body* _b2Box;
        b2PolygonShape _b2BoxShape;
        b2FixtureDef _b2BoxFixDef;
        
        sf::RectangleShape _mGround;
        sf::RectangleShape _mBox;
        
        float PPM;
    };
}

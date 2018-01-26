        keys = SDL_GetKeyboardState(NULL);

        if (keys[SDL_SCANCODE_A]){
            entity->get_component<PositionComponent>().velocity.x = -1.0f;
        }
        if (!keys[SDL_SCANCODE_A]){
            if (entity->get_component<PositionComponent>().velocity.x < 0)
            entity->get_component<PositionComponent>().velocity.x = 0.0f;
        }
        if (keys[SDL_SCANCODE_D]){
            entity->get_component<PositionComponent>().velocity.x = 1.0f;
        }
        if (!keys[SDL_SCANCODE_D]){
            if (entity->get_component<PositionComponent>().velocity.x > 0)
            entity->get_component<PositionComponent>().velocity.x = 0.0f;
        }
        if (keys[SDL_SCANCODE_W]){
            entity->get_component<PositionComponent>().velocity.y = -1.0f;
        }
        if (!keys[SDL_SCANCODE_W]){
            if (entity->get_component<PositionComponent>().velocity.y < 0)
            entity->get_component<PositionComponent>().velocity.y = 0.0f;
        }
        if (keys[SDL_SCANCODE_S]){
            entity->get_component<PositionComponent>().velocity.y = 1.0f;
        }
        if (!keys[SDL_SCANCODE_S]){
            if (entity->get_component<PositionComponent>().velocity.y > 0)
            entity->get_component<PositionComponent>().velocity.y = 0.0f;
        }

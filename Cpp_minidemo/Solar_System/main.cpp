#include <iostream>
#include <SDL.h>
#include <cmath>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

struct Planet {
    SDL_Rect rect;
    double orbitRadius;
    double orbitSpeed;
    double angle;
    SDL_Texture* const texture;

    Planet(int w, int h, double orbitRadius, double orbitSpeed, double angle, SDL_Texture* texture)
        : rect{ 0, 0, w, h }, orbitRadius(orbitRadius), orbitSpeed(orbitSpeed), angle(angle), texture(texture) {}

    void updatePosition(int sunX, int sunY) {
        rect.x = sunX + static_cast<int>(orbitRadius * cos(angle)) - rect.w / 2;
        rect.y = sunY + static_cast<int>(orbitRadius * sin(angle)) - rect.h / 2;
        angle += orbitSpeed;
    }

    void render(SDL_Renderer* renderer) {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
};

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized: " << SDL_GetError();
        return -1;
    }
    else {
        std::cout << "SDL video system is ready to go\n";
    }

    window = SDL_CreateWindow("C++ SDL2 Window", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface* surfaceStars = SDL_LoadBMP("./images/stars.bmp");
    SDL_Surface* surfaceSun = SDL_LoadBMP("./images/sun.bmp");
    SDL_Surface* surfaceMercury = SDL_LoadBMP("./images/mercury.bmp");
    SDL_Surface* surfaceVenus = SDL_LoadBMP("./images/venus.bmp");
    SDL_Surface* surfaceEarth = SDL_LoadBMP("./images/earth.bmp");
    SDL_Surface* surfaceMars = SDL_LoadBMP("./images/mars.bmp");
    SDL_Surface* surfaceJupiter = SDL_LoadBMP("./images/jupiter.bmp");
    SDL_Surface* surfaceSaturn = SDL_LoadBMP("./images/saturn.bmp");
    SDL_Surface* surfaceUranus = SDL_LoadBMP("./images/uranus.bmp");
    SDL_Surface* surfaceNeptune = SDL_LoadBMP("./images/neptune.bmp");

    SDL_Texture* textureStars = SDL_CreateTextureFromSurface(renderer, surfaceStars);
    SDL_Texture* textureSun = SDL_CreateTextureFromSurface(renderer, surfaceSun);
    SDL_Texture* textureMercury = SDL_CreateTextureFromSurface(renderer, surfaceMercury);
    SDL_Texture* textureVenus = SDL_CreateTextureFromSurface(renderer, surfaceVenus);
    SDL_Texture* textureEarth = SDL_CreateTextureFromSurface(renderer, surfaceEarth);
    SDL_Texture* textureMars = SDL_CreateTextureFromSurface(renderer, surfaceMars);
    SDL_Texture* textureJupiter = SDL_CreateTextureFromSurface(renderer, surfaceJupiter);
    SDL_Texture* textureSaturn = SDL_CreateTextureFromSurface(renderer, surfaceSaturn);
    SDL_Texture* textureUranus = SDL_CreateTextureFromSurface(renderer, surfaceUranus);
    SDL_Texture* textureNeptune = SDL_CreateTextureFromSurface(renderer, surfaceNeptune);

    SDL_FreeSurface(surfaceStars);
    SDL_FreeSurface(surfaceSun);
    SDL_FreeSurface(surfaceMercury);
    SDL_FreeSurface(surfaceVenus);
    SDL_FreeSurface(surfaceEarth);
    SDL_FreeSurface(surfaceMars);
    SDL_FreeSurface(surfaceJupiter);
    SDL_FreeSurface(surfaceSaturn);
    SDL_FreeSurface(surfaceUranus);
    SDL_FreeSurface(surfaceNeptune);

    SDL_Rect sunRect = { (SCREEN_WIDTH - 100) / 2, (SCREEN_HEIGHT - 100) / 2, 100, 100 };

    SDL_Rect backgroundRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

    int sunXCoordinate = sunRect.x + sunRect.w / 2;
    int sunYCoordinate = sunRect.y + sunRect.h / 2;

    Planet mercury = { 30, 30, 80.0, 0.02 * 4.15, 45.0, textureMercury };
    Planet venus = { 40, 40, 125.0, 0.02 * 1.62, 90.0, textureVenus };
    Planet earth = { 50, 50, 175.0, 0.02, 135.0, textureEarth };
    Planet mars = { 40, 40, 225.0, 0.02 * 0.53, 180.0, textureMars };
    Planet jupiter = { 80, 80, 290.0, 0.02 * 0.084, 225.0, textureJupiter };
    Planet saturn = { 70, 70, 380.0, 0.02 * 0.034, 270.0, textureSaturn };
    Planet uranus = { 60, 60, 470.0, 0.02 * 0.012, 315.0, textureUranus };
    Planet neptune = { 60, 60, 550.0, 0.02 * 0.006, 0.0, textureNeptune };

    Planet planets[] = { mercury, venus, earth, mars, jupiter, saturn, uranus, neptune };

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    bool running = true;
    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
            }
        }

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, textureStars, NULL, &backgroundRect);
        SDL_RenderCopy(renderer, textureSun, NULL, &sunRect);

        for (Planet& planet : planets) {
            planet.updatePosition(sunXCoordinate, sunYCoordinate);
            planet.render(renderer);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);  // ~60 FPS
    }

    SDL_DestroyTexture(textureStars);
    SDL_DestroyTexture(textureSun);
    SDL_DestroyTexture(textureMercury);
    SDL_DestroyTexture(textureVenus);
    SDL_DestroyTexture(textureEarth);
    SDL_DestroyTexture(textureMars);
    SDL_DestroyTexture(textureJupiter);
    SDL_DestroyTexture(textureSaturn);
    SDL_DestroyTexture(textureUranus);
    SDL_DestroyTexture(textureNeptune);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"

int main() {
    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib + ImGui + CMake");
    SetTargetFPS(60);

    rlImGuiSetup(true);

    bool showDemoWindow = true;
    float sliderValue = 0.5f;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        DrawText("raylib + ImGui starter", 20, 20, 24, RAYWHITE);

        rlImGuiBegin();

        ImGui::Begin("Hello, ImGui!");
        ImGui::Text("Cross-platform starter project");
        ImGui::Checkbox("Show ImGui Demo", &showDemoWindow);
        ImGui::SliderFloat("Value", &sliderValue, 0.0f, 1.0f);
        ImGui::Text("FPS: %d", GetFPS());
        ImGui::End();

        if (showDemoWindow) {
            ImGui::ShowDemoWindow(&showDemoWindow);
        }

        rlImGuiEnd();

        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();
    return 0;
}

// IMGUI
#include "libUI/imgui.h"
#include "libUI/imgui_impl_glfw.h"
#include "libUI/imgui_impl_opengl3.h"
// GLAD
#include "Core/include/glad/glad.h"
// Others
#include "Core/Math/Math.hpp"
#include "Core/Math/include/Vectorf.hpp"
#include <EditorUI/EditorUI.hpp>
#include <Window/Window.hpp>
#include <iostream>
Editor2D::Window &window = window.GetInstance();
EditorUI &editorui = editorui.GetInstance();

const char *glslVersion = "#version 460 core";

void DrawFunctions();
void styling();
ImGuiStyle *style;
int main(int, char **) {
  editorui.bindings.SceneHeirarchy = false;
  std::cout << "Hello, world!\n";

  bool showDemoWindow = true;
  // IMGUI Init
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  io.Fonts->AddFontFromFileTTF(
      "Resources/EditorFont.ttf", 16);
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
  // ImGui::StyleColorsLight();

  ImGui_ImplGlfw_InitForOpenGL(window.WHandle, true);
  ImGui_ImplOpenGL3_Init(glslVersion);

  gladLoadGL();
  while (!window.ExitStatus()) {
    window.WPollEvents();
    editorui.bindings.SceneHeirarchy =
        (glfwGetKey(window.WHandle, GLFW_KEY_H) == true);
    {
      // UI Update
      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplGlfw_NewFrame();
      ImGui::NewFrame();
      ImGui::ShowDemoWindow(&showDemoWindow);

      // Calls UI Draw Calls
      DrawFunctions();

      // Styling
      styling();
      ImGui::Render();
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    {
      // UI Update
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    window.update();

    { // handling Viewports
      if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        GLFWwindow *backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);
      }
    }
    window.WSwapBuffers();
  }
  {
    // Shuting down UI
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
  }

  return EXIT_SUCCESS;
}
void styling() {
  style = &ImGui::GetStyle();
  style->WindowMinSize = ImVec2(350, 150);
  style->FrameRounding = 6;
}
void DrawFunctions() { editorui.HeirarchyWindow(); }
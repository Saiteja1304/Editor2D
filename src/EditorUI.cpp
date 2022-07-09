// IMGUI
#include "../libUI/imgui.h"
#include "../libUI/imgui_impl_glfw.h"
#include "../libUI/imgui_impl_opengl3.h"
#include <EditorUI/EditorUI.hpp>
void EditorUI::HeirarchyWindow() {
  if (ImGui::Begin("Scene Heirarchy", &bindings.SceneHeirarchy)) {
    ImGui::Text("GameObjects");
    ImGui::End();
  }
}
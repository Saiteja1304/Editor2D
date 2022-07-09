#ifndef EDITORUI_H
#define EDITORUI_H
struct EditorUIBindings {
  bool SceneHeirarchy;
};
class EditorUI {
public:
EditorUIBindings bindings;
  static EditorUI &GetInstance() {
    static EditorUI Instance;
    return Instance;
  }
  void HeirarchyWindow();

private:
  EditorUI() {}
  EditorUI(EditorUI const &);
  void operator=(EditorUI const &);
};

#endif
// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#ifndef INCLUDE_JET_GFX_GLFW_WINDOW_H_
#define INCLUDE_JET_GFX_GLFW_WINDOW_H_

#ifdef JET_USE_GL

#include <jet.gfx/gl_renderer.h>
#include <jet.gfx/glfw_app.h>
#include <jet.gfx/window.h>
#include <jet/macros.h>

struct GLFWwindow;

namespace jet {
namespace gfx {

//!
//! \brief Helper class for GLFW-based window.
//!
//! \see GlfwApp
//!
class GlfwWindow final : public Window {
 public:
    //! Returns the framebuffer size.
    //! Note that the framebuffer size can be different from the window size,
    //! especially on a Retina display (2x the window size).
    Vector2UZ framebufferSize() const override;

    //! Returns the window size.
    Vector2UZ windowSize() const override;

    //! Request to render given number of frames to the renderer.
    void requestRender(unsigned int numFrames) override;

    //! Sets swap interval.
    void setSwapInterval(int interval) override;

    //! Returns raw GLFW window object.
    GLFWwindow* glfwWindow() const;

 private:
    GLFWwindow* _window = nullptr;

    MouseButtonType _pressedMouseButton = MouseButtonType::kNone;
    ModifierKey _lastModifierKey = ModifierKey::kNone;

    unsigned int _numRequestedRenderFrames = 0;

    int _width = 256;
    int _height = 256;
    bool _hasPointerEntered = false;
    double _pointerPosX = 0.0;
    double _pointerPosY = 0.0;
    double _pointerDeltaX = 0.0;
    double _pointerDeltaY = 0.0;

    int _swapInterval = 0;

    GlfwWindow(const std::string& title, int width, int height);

    void render();

    void resize(int width, int height);

    void update();

    void key(int key, int scancode, int action, int mods);

    void pointerButton(int button, int action, int mods);

    void pointerMoved(double x, double y);

    void pointerEnter(bool entered);

    void mouseWheel(double deltaX, double deltaY);

    double getScaleFactor() const;

    friend class GlfwApp;
};

//! Shared typed for GlfwWindow.
using GlfwWindowPtr = std::shared_ptr<GlfwWindow>;

}  // namespace gfx
}  // namespace jet

#endif  // JET_USE_GL

#endif  // INCLUDE_JET_GFX_GLFW_WINDOW_H_
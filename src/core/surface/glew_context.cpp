#include <texplr/core/surface/glew_context.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

namespace texplr {

GLEWContext::GLEWContext(std::shared_ptr<GameWindow> window)
    : m_isInitialized(false)
    , m_window(window)
{
}

GLEWContext::~GLEWContext()
{
    destroy();
}

void GLEWContext::init()
{
    if (m_isInitialized) {
        return;
    }

    glfwMakeContextCurrent((GLFWwindow*)m_window->getNativeHandle());

    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("Couldn't initialize GLEW!");
    }

    m_isInitialized = true;
}

void GLEWContext::destroy()
{
    if (m_isInitialized) {
        m_isInitialized = false;
    }
}

} // namespace texplr

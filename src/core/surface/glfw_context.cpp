#include <texplr/core/surface/glfw_context.h>

#include <stdexcept>

#include <GLFW/glfw3.h>

namespace texplr {

GLFWContext::GLFWContext(uint8_t glMajorVer, uint8_t glMinorVer)
    : m_isInitialized(false)
    , m_glMajorVer(glMajorVer)
    , m_glMinorVer(glMinorVer)
{
}

GLFWContext::~GLFWContext()
{
    destroy();
}

void GLFWContext::init()
{
    if (m_isInitialized) {
        return;
    }

    if (!glfwInit()) {
        throw std::runtime_error("Couldn't initialize GLFW!");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_glMajorVer);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_glMinorVer);

    m_isInitialized = true;
}

void GLFWContext::pollEvents()
{
    glfwPollEvents();
}

void GLFWContext::destroy()
{
    if (m_isInitialized) {
        glfwTerminate();

        m_isInitialized = false;
    }
}

} // namespace texplr

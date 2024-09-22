#pragma once

#include <cstdint>

namespace texplr {

class GLFWContext {
public:
    GLFWContext(uint8_t glMajorVer, uint8_t glMinorVer);
    ~GLFWContext();

    void init();
    void pollEvents();
    void destroy();

private:
    bool m_isInitialized;
    uint8_t m_glMajorVer;
    uint8_t m_glMinorVer;
};

} // namespace texplr

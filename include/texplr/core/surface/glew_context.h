#pragma once

#include "./game_window.h"

namespace texplr {

class GLEWContext {
public:
    GLEWContext(std::shared_ptr<GameWindow> window);
    ~GLEWContext();

    void init();
    void destroy();

private:
    std::shared_ptr<GameWindow> m_window;

    bool m_isInitialized;
};

} // namespace texplr

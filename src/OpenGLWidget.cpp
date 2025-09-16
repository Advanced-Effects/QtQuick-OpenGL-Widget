#include "OpenGLWidget.h"

#include <GLFW/glfw3.h>
#include <QPoint>

QuickGLWidget::QuickGLWidget(QObject *parent = nullptr)
        : QQuickWidget(parent) {
        initializeGL();
        createGLWindow();
        mainWindowLoop();
};

QRect QuickGLWidget::widgetGeometry() {
        // Map the widget's top-left corner to global (screen) coordinates
        QPoint topLeft = mapToGlobal(QPoint(0, 0));
        QSize size = size();

        return QRect(topLeft, size);
};

// Returns 'false' if initialization goes wrong
bool QuickGLWidget::initializeGL() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        #ifdef __APPLE__
                glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif

        return glfwInit(); // 'false' if gone wrong
};
GLFWwindow* QuickGLWidget::createGLWindow() {
        auto window = glfwCreateWindow(500, 500, "", glfwGetPrimaryMonitor(), nullptr);

        if (!window) {
                glfwTerminate();
                return nullptr;
        }

        return window;
};
int QuickGLWidget::mainWindowLoop() {
        if (m_glContext == nullptr) {
                return EXIT_FAILURE;
        }

        // Runs until the window is destroyed
        while (!glfwWindowShouldClose(m_glContext)) {
                // It's okay to draw
                paintThisFrame();

                // 'Prepare' next frame
                glfwSwapBuffers(m_glContext);
                glfwPollEvents();
        }

        glfwDestroyWindow(m_glContext);

        return 0;
};

void QuickGLWidget::resizeGLWindow(int x,
                                   int y,
                                   int width,
                                   int height)
{
        glfwSetWindowPos(m_glContext, x, y);
        glfwSetWindowSize(m_glContext, width, height);
};

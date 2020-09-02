#include "sdpch.h"

#include "OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace SandEngine {

    void OpenGLMessageCallback(
        unsigned source,
        unsigned type,
        unsigned id,
        unsigned severity,
        int length,
        const char* message,
        const void* userParam)
    {
        switch (severity)
        {
        case GL_DEBUG_SEVERITY_HIGH:         SE_LOG_CRITICAL_CORE(message); return;
        case GL_DEBUG_SEVERITY_MEDIUM:       SE_LOG_ERROR_CORE(message); return;
        case GL_DEBUG_SEVERITY_LOW:          SE_LOG_WARN_CORE(message); return;
        case GL_DEBUG_SEVERITY_NOTIFICATION: SE_LOG_TRACE_CORE(message); return;
        }

        SE_CORE_ASSERT(false, "Unknown severity level!");
    }

    void COpenGLRendererAPI::Init()
    {
    #ifdef SE_DEBUG
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(OpenGLMessageCallback, nullptr);

        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
    #endif
        //glEnable(GL_BLEND);
        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        //glEnable(GL_DEPTH_TEST);
    }

    void COpenGLRendererAPI::SetClearColor(const glm::vec4& vec4Color)
    {
        glClearColor(vec4Color.r, vec4Color.g, vec4Color.b, vec4Color.a);
    }

    void COpenGLRendererAPI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);// | GL_DEPTH_BUFFER_BIT);
    }

    void COpenGLRendererAPI::DrawIndexed(const Ref<CVertexArray>& pVertexArray, uint32_t nIndexCount)
    {
        uint32_t nCount = nIndexCount ? nIndexCount : pVertexArray->GetIndexBuffer()->GetCount();
        glDrawElements(GL_TRIANGLES, nCount, GL_UNSIGNED_INT, nullptr);
    }

}
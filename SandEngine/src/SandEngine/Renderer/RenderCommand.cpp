#include "sdpch.h"

#include "RenderCommand.h"

namespace SandEngine {

    Scope<CRendererAPI> CRenderCommand::s_pRendererAPI = CRendererAPI::Create();

}
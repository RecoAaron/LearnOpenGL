#pragma once
/*************************************************
 * Copyright: @SandEngine
 * Author: RecoAaron
 * Date:2020-08-15
 * Description: Ӧ�ó�����
*************************************************/
#include "SandEngine/Core/Base.h"

namespace SandEngine {

    class SE_API CApplication
    {
    public:
        CApplication();
        virtual ~CApplication();

        /// Ӧ�ó���ʼ����
        void Run();
    };

    /// �Զ��崴��Ӧ�ó���ķ���
    CApplication* CreateApplication();
}
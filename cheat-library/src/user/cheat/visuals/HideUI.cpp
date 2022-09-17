#include "pch-il2cpp.h"
#include "HideUI.h"

#include <helpers.h>
#include <cheat/events.h>

namespace cheat::feature
{
    app::GameObject* ui_camera{};
    app::GameObject* DamageOverlay{};
    app::GameObject* RadarOverlay{};
    app::GameObject* TopRightOverlay{};
    app::GameObject* PingOverlay{};
    app::GameObject* TeamOverlay{};
    app::GameObject* SkillOverlay{};
    app::GameObject* HpOverlay{};
    app::GameObject* ChatOverlay{};
    app::GameObject* RewardOverlay{};
    app::GameObject* InteractOverlay{};
    app::GameObject* ArLevelOverlay{};

    HideUI::HideUI() : Feature(),
        NFEX(f_Enabled, "Hide UI", "HideUI", "Visuals", false, false),
        NFEX(f_DamageOverlayHide, "Hide UI", "HideUI", "Visuals", false, false),
        NFEX(f_RadarOverlayHide, "Hide UI", "HideUI", "Visuals", false, false),
        NFEX(f_TopRightOverlayHide, "Hide UI", "HideUI", "Visuals", false, false),
        NFEX(f_PingOverlayHide, "Hide UI", "HideUI", "Visuals", false, false),
        NFEX(f_TeamOverlayHide, "Hide UI", "HideUI", "Visuals", false, false),
        NFEX(f_SkillOverlayHide, "Hide UI", "HideUI", "Visuals", false, false),
        NFEX(f_HpOverlayHide, "Hide UI", "HideUI", "Visuals", false, false),
        NFEX(f_ChatOverlayHide, "Hide UI", "HideUI", "Visuals", false, false),

        NFEX(f_RewardOverlayHide, "Hide UI", "HideUI", "Visuals", false, false),
        NFEX(f_InteractOverlayHide, "Hide UI", "HideUI", "Visuals", false, false),
        NFEX(f_ArLevelOverlayHide, "Hide UI", "HideUI", "Visuals", false, false)

    {
        events::GameUpdateEvent += MY_METHOD_HANDLER(HideUI::OnGameUpdate);
    }

    const FeatureGUIInfo& HideUI::GetGUIInfo() const
    {
        static const FeatureGUIInfo info{ "HideUI", "Visuals", false };
        return info;
    }

    void HideUI::DrawMain()
    {
        ConfigWidget(f_Enabled, "Hide in-game UI.\nWhen you switch to another scene (e.g. into Domains), turn off and re-enable this feature");
        ImGui::BeginGroupPanel("Advance Hide UI");
        {
            ImGui::Text("Please get into the game before using any function below!");
            ConfigWidget("Hide Damage Overlay", f_DamageOverlayHide, "Hide/Unhide damage output overlay");
            ConfigWidget("Hide Radar Overlay", f_RadarOverlayHide, "Hide/Unhide radar and top left buttons overlay");
            ConfigWidget("Hide Top Buttons Overlay", f_TopRightOverlayHide, "Hide/Unhide top right buttons overlay");
            ConfigWidget("Hide Ping Overlay", f_PingOverlayHide, "Hide/Unhide ping overlay");
            ConfigWidget("Hide Team Overlay", f_TeamOverlayHide, "Hide/Unhide team overlay");
            ConfigWidget("Hide Skills Overlay", f_SkillOverlayHide, "Hide/Unhide bottom right elemental skill and ultimate overlay");
            ImGui::SameLine();
            ImGui::Text("Hide skills overlay will also disable skills usage!");
            ConfigWidget("Hide HP & EXP Bar Overlay", f_HpOverlayHide, "Hide/Unhide HP bar and EXP overlay");
            ConfigWidget("Hide Chat Overlay", f_ChatOverlayHide, "Hide/Unhide chat box overlay");
            ConfigWidget("Hide Interact Overlay", f_InteractOverlayHide, "Hide/Unhide interact overlay (press F to...)");
            ConfigWidget("Hide Rewards Overlay", f_RewardOverlayHide, "Hide/Unhide rewards overlay");
            ConfigWidget("Hide AR Level Notification Overlay", f_ArLevelOverlayHide, "Hide/Unhide AR level notification overlay");
        }
        ImGui::EndGroupPanel();
    }

    bool HideUI::NeedStatusDraw() const
    {
        return f_Enabled;
    }

    void HideUI::DrawStatus()
    {
        ImGui::Text("HideUI");
    }

    HideUI& HideUI::GetInstance()
    {
        static HideUI instance;
        return instance;
    }

    void HideUI::OnGameUpdate()
    {
        if (f_Enabled)
        {
            if (ui_camera == nullptr)
                ui_camera = app::GameObject_Find(string_to_il2cppi("/UICamera"), nullptr);

            if (ui_camera->fields._.m_CachedPtr != nullptr)
                app::GameObject_SetActive(ui_camera, false, nullptr);
        }
        else
        {
            if (ui_camera)
            {
                if (ui_camera->fields._.m_CachedPtr != nullptr)
                    app::GameObject_SetActive(ui_camera, true, nullptr);

                ui_camera = nullptr;
            }
        }
        //dmg overlay
        DamageOverlay = app::GameObject_Find(string_to_il2cppi("/Canvas/Pages/InLevelMainPage/GrpMainPage/ParticleDamageTextContainer"), nullptr);
        if (f_DamageOverlayHide)
        {
            if (DamageOverlay == nullptr)
                return;
            
            if (DamageOverlay->fields._.m_CachedPtr != nullptr)
                app::GameObject_SetActive(DamageOverlay, false, nullptr);
        }
        else
        {
            if (DamageOverlay)
            {
                if (DamageOverlay->fields._.m_CachedPtr != nullptr)
                    app::GameObject_SetActive(DamageOverlay, true, nullptr);
            }
        }
        //radar overlay
        RadarOverlay = app::GameObject_Find(string_to_il2cppi("/Canvas/Pages/InLevelMainPage/GrpMainPage/MapInfo"), nullptr);
        if (f_RadarOverlayHide)
        {
            if (RadarOverlay == nullptr)
                return;
            
            if (RadarOverlay->fields._.m_CachedPtr != nullptr)
                app::GameObject_SetActive(RadarOverlay, false, nullptr);
        }
        else
        {
            if (RadarOverlay)
            {
                if (RadarOverlay->fields._.m_CachedPtr != nullptr)
                    app::GameObject_SetActive(RadarOverlay, true, nullptr);
            }
        }
        //top btn overlay
        TopRightOverlay = app::GameObject_Find(string_to_il2cppi("/Canvas/Pages/InLevelMainPage/GrpMainPage/GrpMainBtn"), nullptr);
        if (f_TopRightOverlayHide)
        {
            
            if (TopRightOverlay == nullptr)
                return;

            if (TopRightOverlay->fields._.m_CachedPtr != nullptr)
                app::GameObject_SetActive(TopRightOverlay, false, nullptr);
        }
        else
        {
            if (TopRightOverlay)
            {
                if (TopRightOverlay->fields._.m_CachedPtr != nullptr)
                    app::GameObject_SetActive(TopRightOverlay, true, nullptr);
            }
        }
        //ping overlay
        PingOverlay = app::GameObject_Find(string_to_il2cppi("/Canvas/Pages/InLevelMainPage/GrpMainPage/NetworkLatency"), nullptr);
        if (f_PingOverlayHide)
        {
            if (PingOverlay == nullptr)
                return;

            if (PingOverlay->fields._.m_CachedPtr != nullptr)
                app::GameObject_SetActive(PingOverlay, false, nullptr);
        }
        else
        {
            if (PingOverlay)
            {
                if (PingOverlay->fields._.m_CachedPtr != nullptr)
                    app::GameObject_SetActive(PingOverlay, true, nullptr);
            }
        }
        //team overlay
        TeamOverlay = app::GameObject_Find(string_to_il2cppi("/Canvas/Pages/InLevelMainPage/GrpMainPage/TeamBtnContainer"), nullptr);
        if (f_TeamOverlayHide)
        {
            if (TeamOverlay == nullptr)
                return;

            if (TeamOverlay->fields._.m_CachedPtr != nullptr)
                app::GameObject_SetActive(TeamOverlay, false, nullptr);
        }
        else
        {
            if (TeamOverlay)
            {
                if (TeamOverlay->fields._.m_CachedPtr != nullptr)
                    app::GameObject_SetActive(TeamOverlay, true, nullptr);
            }
        }
        //skills overlay
        SkillOverlay = app::GameObject_Find(string_to_il2cppi("/Canvas/Pages/InLevelMainPage/GrpMainPage/ActionPanelContainer"), nullptr);
        if (f_SkillOverlayHide)
        {
            if (SkillOverlay == nullptr)
                return;

            if (SkillOverlay->fields._.m_CachedPtr != nullptr)
                app::GameObject_SetActive(SkillOverlay, false, nullptr);
        }
        else
        {
            if (SkillOverlay)
            {
                if (SkillOverlay->fields._.m_CachedPtr != nullptr)
                    app::GameObject_SetActive(SkillOverlay, true, nullptr);
            }
        }
        //hp bar Overlay
        HpOverlay = app::GameObject_Find(string_to_il2cppi("/Canvas/Pages/InLevelMainPage/GrpMainPage/GameInfo"), nullptr);
        if (f_HpOverlayHide)
        {
            if (HpOverlay == nullptr)
                return;

            if (HpOverlay->fields._.m_CachedPtr != nullptr)
                app::GameObject_SetActive(HpOverlay, false, nullptr);
        }
        else
        {
            if (HpOverlay)
            {
                if (HpOverlay->fields._.m_CachedPtr != nullptr)
                    app::GameObject_SetActive(HpOverlay, true, nullptr);
            }
        }
        //chat Overlay
        ChatOverlay = app::GameObject_Find(string_to_il2cppi("/Canvas/Pages/InLevelMainPage/GrpMainPage/Chat"), nullptr);
        if (f_ChatOverlayHide)
        {
            if (ChatOverlay == nullptr)
                return;

            if (ChatOverlay->fields._.m_CachedPtr != nullptr)
                app::GameObject_SetActive(ChatOverlay, false, nullptr);
        }
        else
        {
            if (ChatOverlay)
            {
                if (ChatOverlay->fields._.m_CachedPtr != nullptr)
                    app::GameObject_SetActive(ChatOverlay, true, nullptr);
            }
        }
        //reward overlay
        RewardOverlay = app::GameObject_Find(string_to_il2cppi("/Canvas/SpecialDialogs"), nullptr);
        if (f_RewardOverlayHide)
        {
            if (RewardOverlay == nullptr)
                return;

            if (RewardOverlay->fields._.m_CachedPtr != nullptr)
                app::GameObject_SetActive(RewardOverlay, false, nullptr);
        }
        else
        {
            if (RewardOverlay)
            {
                if (RewardOverlay->fields._.m_CachedPtr != nullptr)
                    app::GameObject_SetActive(RewardOverlay, true, nullptr);
            }
        }
        //interact overlay
        InteractOverlay = app::GameObject_Find(string_to_il2cppi("/Canvas/Pages/InLevelMainPage/GrpMainPage/InteePanel"), nullptr);
        if (f_InteractOverlayHide)
        {
            if (InteractOverlay == nullptr)
                return;

            if (InteractOverlay->fields._.m_CachedPtr != nullptr)
                app::GameObject_SetActive(InteractOverlay, false, nullptr);
        }
        else
        {
            if (InteractOverlay)
            {
                if (InteractOverlay->fields._.m_CachedPtr != nullptr)
                    app::GameObject_SetActive(InteractOverlay, true, nullptr);
            }
        }
        //ar level overlay
        ArLevelOverlay = app::GameObject_Find(string_to_il2cppi("/Canvas/SuspendBars/PlayerExpTipsDialog"), nullptr);
        if (f_ArLevelOverlayHide)
        {
            if (ArLevelOverlay == nullptr)
                return;

            if (ArLevelOverlay->fields._.m_CachedPtr != nullptr)
                app::GameObject_SetActive(ArLevelOverlay, false, nullptr);
        }
        else
        {
            if (ArLevelOverlay)
            {
                if (ArLevelOverlay->fields._.m_CachedPtr != nullptr)
                    app::GameObject_SetActive(ArLevelOverlay, true, nullptr);
            }
        }
    }
}
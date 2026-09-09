#include "pch.h"
#include "App.xaml.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::HelloWinUI::implementation
{
    App::App()
    {
        InitializeComponent();
    }

    void App::OnLaunched(LaunchActivatedEventArgs const&)
    {
        using namespace Microsoft::UI::Xaml::Media;
        using namespace Microsoft::UI::Windowing;

        window = Window();
        window.Title(L"Hello WinUI");
        window.AppWindow().Resize(Windows::Graphics::SizeInt32{960, 640});

        // Extend Mica through the content and title bar.
        window.SystemBackdrop(MicaBackdrop());
        window.ExtendsContentIntoTitleBar(true);
        window.AppWindow().TitleBar().PreferredTheme(
            TitleBarTheme::UseDefaultAppMode);

        Grid root;

        RowDefinition titleRow;
        titleRow.Height(GridLength{1, GridUnitType::Auto});

        RowDefinition contentRow;
        contentRow.Height(GridLength{1, GridUnitType::Star});

        root.RowDefinitions().Append(titleRow);
        root.RowDefinitions().Append(contentRow);

        // WinUI title bar; Windows retains the caption buttons.
        TitleBar titleBar;
        titleBar.Title(L"Hello WinUI");

        FontIconSource icon;
        icon.FontFamily(FontFamily(L"Segoe Fluent Icons"));
        icon.Glyph(L"\uE80F");
        titleBar.IconSource(icon);

        root.Children().Append(titleBar);

        // A themed content surface above the Mica background.
        Border card;
        card.Style(
            Resources().Lookup(box_value(L"ContentCardStyle")).as<Style>());
        Grid::SetRow(card, 1);

        StackPanel content;
        content.Spacing(16);

        TextBlock heading;
        heading.Text(L"Welcome");
        heading.Style(
            Resources().Lookup(box_value(L"TitleTextBlockStyle")).as<Style>());

        TextBlock description;
        description.Text(L"Windows 11 desktop application with native appearance.");
        description.TextWrapping(TextWrapping::Wrap);
        description.Style(
            Resources().Lookup(box_value(L"BodyTextBlockStyle")).as<Style>());

        Button button;
        button.Content(box_value(L"Click me"));
        button.HorizontalAlignment(HorizontalAlignment::Left);
        button.Style(
            Resources().Lookup(box_value(L"AccentButtonStyle")).as<Style>());

        button.Click([](
            Windows::Foundation::IInspectable const& sender,
            RoutedEventArgs const&)
        {
            sender.as<Button>().Content(box_value(L"Hello from C++"));
        });

        content.Children().Append(heading);
        content.Children().Append(description);
        content.Children().Append(button);

        card.Child(content);
        root.Children().Append(card);

        window.Content(root);
        window.SetTitleBar(titleBar);
        window.Activate();
    }
}

int WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
    winrt::init_apartment(winrt::apartment_type::single_threaded);

    winrt::Microsoft::UI::Xaml::Application::Start([](auto&&)
    {
        winrt::make<winrt::HelloWinUI::implementation::App>();
    });

    return 0;
}
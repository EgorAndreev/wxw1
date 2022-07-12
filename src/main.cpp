#include <wx/wx.h>
#include <wx/msgdlg.h>
class Frame : public wxFrame {
public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Test") {
    button->Bind(wxEVT_BUTTON, [](wxCommandEvent& event) {
        wxMessageDialog dlg(NULL, wxT("Hello world!"),
            wxT("Test dialog"),
            wxCANCEL | wxICON_INFORMATION);
            dlg.ShowModal();});
    }
    private:
        wxPanel* panel = new wxPanel(this);
        wxButton* button = new wxButton(panel, wxID_ANY, "Test", { 10, 10 });
};
class Application : public wxApp {
    bool OnInit() override {
        (new Frame())->Show();
        return true;
    }
};
wxIMPLEMENT_APP(Application);
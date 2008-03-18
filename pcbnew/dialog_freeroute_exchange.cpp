/////////////////////////////////////////////////////////////////////////////

// Name:        dialog_freeroute_exchange.cpp
// Purpose:
// Author:      jean-pierre Charras
// Modified by:
// Created:     14/03/2008 09:19:27
// RCS-ID:
// Copyright:   kicad team
// Licence:
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 14/03/2008 09:19:27

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "fctsys.h"
#include "common.h"
#include "pcbnew.h"

#include "dialog_freeroute_exchange.h"

////@begin XPM images
////@end XPM images

#define FREEROUTE_URL_KEY wxT( "freeroute_url" )
#define FREEROUTE_RUN_KEY wxT( "freeroute_command" )


/**********************************************************************/
void WinEDA_PcbFrame::Access_to_External_Tool( wxCommandEvent& event )
/**********************************************************************/

/* Run an external tool (currently, only freeroute)
 */
{
    dialog_freeroute_exchange dialog( this );

    dialog.ShowModal();
}


/*!
 * dialog_freeroute_exchange type definition
 */

IMPLEMENT_DYNAMIC_CLASS( dialog_freeroute_exchange, wxDialog )


/*!
 * dialog_freeroute_exchange event table definition
 */

BEGIN_EVENT_TABLE( dialog_freeroute_exchange, wxDialog )

////@begin dialog_freeroute_exchange event table entries
    EVT_CLOSE( dialog_freeroute_exchange::OnCloseWindow )

    EVT_BUTTON( ID_CREATE_EXPORT_DSN_FILE, dialog_freeroute_exchange::OnCreateExportDsnFileClick )

    EVT_BUTTON( ID_RUN_FREEROUTE, dialog_freeroute_exchange::OnRunFreerouteClick )

    EVT_BUTTON( ID_IMPORT_FREEROUTE_DSN_FILE, dialog_freeroute_exchange::OnImportFreerouteDsnFileClick )

    EVT_BUTTON( wxID_CLOSE, dialog_freeroute_exchange::OnCloseClick )

    EVT_BUTTON( ID_GOTO_FREEROUTE_WEB_SITE, dialog_freeroute_exchange::OnGotoFreerouteWebSiteClick )

    EVT_TEXT( ID_TEXT_EDIT_FR_URL, dialog_freeroute_exchange::OnTextEditFrUrlUpdated )

    EVT_TEXT( ID_TEXT_EDIT_FR_CMD, dialog_freeroute_exchange::OnTextEditFrCmdUpdated )

////@end dialog_freeroute_exchange event table entries

END_EVENT_TABLE()


/*!
 * dialog_freeroute_exchange constructors
 */

dialog_freeroute_exchange::dialog_freeroute_exchange()
{
    Init();
}


dialog_freeroute_exchange::dialog_freeroute_exchange( wxWindow* parent,
                                                      wxWindowID id,
                                                      const wxString& caption,
                                                      const wxPoint& pos,
                                                      const wxSize& size,
                                                      long style )
{
    m_Parent = (WinEDA_PcbFrame*) parent;
    Init();
    Create( parent, id, caption, pos, size, style );
}


/*!
 * dialog_freeroute_exchange creator
 */

bool dialog_freeroute_exchange::Create( wxWindow* parent,
                                        wxWindowID id,
                                        const wxString& caption,
                                        const wxPoint& pos,
                                        const wxSize& size,
                                        long style )
{
////@begin dialog_freeroute_exchange creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end dialog_freeroute_exchange creation
    return true;
}


/*!
 * dialog_freeroute_exchange destructor
 */

dialog_freeroute_exchange::~dialog_freeroute_exchange()
{
////@begin dialog_freeroute_exchange destruction
////@end dialog_freeroute_exchange destruction
}


/*!
 * Member initialisation
 */

void dialog_freeroute_exchange::Init()
{
////@begin dialog_freeroute_exchange member initialisation
    m_FreeRouteSetupChanged = false;
    m_FreerouteURLName = NULL;
    m_FreerouteURLCommandString = NULL;
////@end dialog_freeroute_exchange member initialisation
}


/*!
 * Control creation for dialog_freeroute_exchange
 */

void dialog_freeroute_exchange::CreateControls()
{
////@begin dialog_freeroute_exchange content construction
    // Generated by DialogBlocks, Tue 18 Mar 2008 16:15:58 CDT (unregistered)

    dialog_freeroute_exchange* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxGROW|wxALL, 5);

    wxButton* itemButton4 = new wxButton( itemDialog1, ID_CREATE_EXPORT_DSN_FILE, _("Export a Specctra Design (*.dsn) File"), wxDefaultPosition, wxDefaultSize, 0 );
    if (dialog_freeroute_exchange::ShowToolTips())
        itemButton4->SetToolTip(_("Export a Specctra DSN file (to FreeRouter)"));
    itemBoxSizer3->Add(itemButton4, 0, wxGROW|wxALL, 5);

    wxButton* itemButton5 = new wxButton( itemDialog1, ID_RUN_FREEROUTE, _("Launch FreeRouter via Browser"), wxDefaultPosition, wxDefaultSize, 0 );
    if (dialog_freeroute_exchange::ShowToolTips())
        itemButton5->SetToolTip(_("User your browser's Java Web Start function to run FreeRouter via Internet"));
    itemBoxSizer3->Add(itemButton5, 0, wxGROW|wxALL, 5);

    wxButton* itemButton6 = new wxButton( itemDialog1, ID_IMPORT_FREEROUTE_DSN_FILE, _("Back Import the Specctra Session (*.ses) File"), wxDefaultPosition, wxDefaultSize, 0 );
    if (dialog_freeroute_exchange::ShowToolTips())
        itemButton6->SetToolTip(_("Merge a session file created by FreeRouter with the current board."));
    itemBoxSizer3->Add(itemButton6, 0, wxGROW|wxALL, 5);

    wxButton* itemButton7 = new wxButton( itemDialog1, wxID_CLOSE, _("&Close"), wxDefaultPosition, wxDefaultSize, 0 );
    if (dialog_freeroute_exchange::ShowToolTips())
        itemButton7->SetToolTip(_("Close this dialog window"));
    itemBoxSizer3->Add(itemButton7, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer2->Add(itemBoxSizer8, 1, wxGROW|wxALL, 5);

    wxButton* itemButton9 = new wxButton( itemDialog1, ID_GOTO_FREEROUTE_WEB_SITE, _("Visit the FreeRouting.net Website with your Browser"), wxDefaultPosition, wxDefaultSize, 0 );
    if (dialog_freeroute_exchange::ShowToolTips())
        itemButton9->SetToolTip(_("Launch your browser and go to the FreeRouting.net website"));
    itemBoxSizer8->Add(itemButton9, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText10 = new wxStaticText( itemDialog1, wxID_STATIC, _("FreeRouting.net URL"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer8->Add(itemStaticText10, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);

    m_FreerouteURLName = new wxTextCtrl( itemDialog1, ID_TEXT_EDIT_FR_URL, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    if (dialog_freeroute_exchange::ShowToolTips())
        m_FreerouteURLName->SetToolTip(_("The URL of the FreeRouting.net website"));
    itemBoxSizer8->Add(m_FreerouteURLName, 1, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxStaticText* itemStaticText12 = new wxStaticText( itemDialog1, wxID_STATIC, _("FreeRouting.net Command"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer8->Add(itemStaticText12, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);

    m_FreerouteURLCommandString = new wxTextCtrl( itemDialog1, ID_TEXT_EDIT_FR_CMD, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    if (dialog_freeroute_exchange::ShowToolTips())
        m_FreerouteURLCommandString->SetToolTip(_("The URL of the JNLP file which Java Web Start uses to launch the FreeRouter"));
    itemBoxSizer8->Add(m_FreerouteURLCommandString, 1, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

////@end dialog_freeroute_exchange content construction

    wxString msg;
    m_Parent->m_Parent->m_EDA_Config->Read( FREEROUTE_URL_KEY, &msg );
    if( msg.IsEmpty() )
        m_FreerouteURLName->SetValue( wxT( "http://www.freerouting.net/" ) );
    else
        m_FreerouteURLName->SetValue( msg );
    msg.Empty();
    m_Parent->m_Parent->m_EDA_Config->Read( FREEROUTE_RUN_KEY, &msg );
    if( msg.IsEmpty() )
        m_FreerouteURLCommandString->SetValue( wxT(
                                                  "http://www.freerouting.net/java/freeroute.jnlp" ) );
    else
        m_FreerouteURLCommandString->SetValue( msg );
}


/*!
 * Should we show tooltips?
 */

bool dialog_freeroute_exchange::ShowToolTips()
{
    return true;
}


/*!
 * Get bitmap resources
 */

wxBitmap dialog_freeroute_exchange::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin dialog_freeroute_exchange bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end dialog_freeroute_exchange bitmap retrieval
}


/*!
 * Get icon resources
 */

wxIcon dialog_freeroute_exchange::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin dialog_freeroute_exchange icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end dialog_freeroute_exchange icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_CREATE_EXPORT_DSN_FILE
 */

void dialog_freeroute_exchange::OnCreateExportDsnFileClick( wxCommandEvent& event )
{
    m_Parent->ExportToSpecctra( event );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_IMPORT_FREEROUTE_DSN_FILE
 */

void dialog_freeroute_exchange::OnImportFreerouteDsnFileClick( wxCommandEvent& event )
{
    m_Parent->ImportSpecctraSession(  event );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RUN_FREEROUTE
 */

void dialog_freeroute_exchange::OnRunFreerouteClick( wxCommandEvent& event )
{
    wxString command = m_FreerouteURLCommandString->GetValue();

    // @todo:
    // 1) add freeroute.jnlp to the Kicad project
    // 2) change this next C++ line simply run $ "javaws freeroute.jnlp" as a system
    //    command, bypassing the browser altogether.  Merely need a PATH to javaws.

    wxLaunchDefaultBrowser( command );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

void dialog_freeroute_exchange::OnGotoFreerouteWebSiteClick( wxCommandEvent& event )
{
    wxString command = m_FreerouteURLName->GetValue();

    wxLaunchDefaultBrowser( command );
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CLOSE
 */

void dialog_freeroute_exchange::OnCloseClick( wxCommandEvent& event )
{
    Close();
}


/*!
 * wxEVT_CLOSE_WINDOW event handler for ID_DIALOG_FREEROUTE_EXCHANGE
 */

void dialog_freeroute_exchange::OnCloseWindow( wxCloseEvent& event )
{
    if( m_FreeRouteSetupChanged )  // Save new config
    {
        m_Parent->m_Parent->m_EDA_Config->Write( FREEROUTE_URL_KEY,
                                                m_FreerouteURLName->GetValue() );
        m_Parent->m_Parent->m_EDA_Config->Write( FREEROUTE_RUN_KEY,
                                                m_FreerouteURLCommandString->GetValue() );
    }

    event.Skip();
}


/*!
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXT_EDIT_FR_URL
 */

void dialog_freeroute_exchange::OnTextEditFrUrlUpdated( wxCommandEvent& event )
{
    m_FreeRouteSetupChanged = true;
}


/*!
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXT_EDIT_FR_CMD
 */

void dialog_freeroute_exchange::OnTextEditFrCmdUpdated( wxCommandEvent& event )
{
    m_FreeRouteSetupChanged = true;
}

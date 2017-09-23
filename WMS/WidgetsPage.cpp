#include "stdafx.h"
#include "WidgetsPage.h"

// ----------------------------------------------------------------------------
// WidgetsPageInfo
// ----------------------------------------------------------------------------

WidgetsPageInfo::WidgetsPageInfo ( Constructor ctor, const wxChar *label, int categories )
	: m_label ( label )
	, m_categories ( categories )
{
	m_ctor = ctor;

	m_next = nullptr;

	// dummy sorting: add and immediately sort in the list according to label
	if ( WidgetsPage::ms_widgetPages )
	{
		WidgetsPageInfo *node_prev = WidgetsPage::ms_widgetPages;
		if ( wxStrcmp ( label, node_prev->GetLabel ( ).c_str ( ) ) < 0 )
		{
			// add as first
			m_next = node_prev;
			WidgetsPage::ms_widgetPages = this;
		}
		else
		{
			WidgetsPageInfo *node_next;
			do
			{
				node_next = node_prev->GetNext ( );
				if ( node_next )
				{
					// add if between two
					if ( wxStrcmp ( label, node_next->GetLabel ( ).c_str ( ) ) < 0 )
					{
						node_prev->SetNext ( this );
						m_next = node_next;
						// force to break loop
						node_next = NULL;
					}
				}
				else
				{
					// add as last
					node_prev->SetNext ( this );
					m_next = node_next;
				}
				node_prev = node_next;
			} while ( node_next );
		}
	}
	else
	{
		// add when first
		WidgetsPage::ms_widgetPages = this;
	}
}

// ----------------------------------------------------------------------------
// WidgetsPage
// ----------------------------------------------------------------------------

WidgetsPageInfo *WidgetsPage::ms_widgetPages = NULL;

WidgetsPage::WidgetsPage ( wxTreebook *book, wxImageList *imaglist, const char *const icon[] )
	: wxPanel ( book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_FULL_REPAINT_ON_RESIZE | wxCLIP_CHILDREN | wxTAB_TRAVERSAL )
{
	imaglist->Add ( wxBitmap ( wxImage ( icon ).Scale ( ICON_SIZE, ICON_SIZE ) ) );
}

/* static */
WidgetAttributes& WidgetsPage::GetAttrs ( )
{
	static WidgetAttributes s_attrs;

	return s_attrs;
}

void WidgetsPage::SetUpWidget ( )
{
	const Widgets widgets = GetWidgets ( );

	for ( Widgets::const_iterator it = widgets.begin ( ); it != widgets.end ( ); ++it )
	{
		wxCHECK_RET ( *it, "NULL widget" );

#if wxUSE_TOOLTIPS
		( *it )->SetToolTip ( GetAttrs ( ).m_tooltip );
#endif // wxUSE_TOOLTIPS
#if wxUSE_FONTDLG
		if ( GetAttrs ( ).m_font.IsOk ( ) )
		{
			(*it)->SetFont ( GetAttrs ( ).m_font );
		}
#endif // wxUSE_FONTDLG
		if ( GetAttrs ( ).m_colFg.IsOk ( ) )
		{
			(*it)->SetForegroundColour ( GetAttrs ( ).m_colFg );
		}

		if ( GetAttrs ( ).m_colBg.IsOk ( ) )
		{
			(*it)->SetBackgroundColour ( GetAttrs ( ).m_colBg );
		}

		(*it)->SetLayoutDirection ( GetAttrs ( ).m_dir );
		(*it)->Enable ( GetAttrs ( ).m_enabled );
		(*it)->Show ( GetAttrs ( ).m_show );

		if ( GetAttrs ( ).m_cursor.IsOk ( ) )
		{
			(*it)->SetCursor ( GetAttrs ( ).m_cursor );
		}

		(*it)->SetWindowVariant ( GetAttrs ( ).m_variant );

		(*it)->Refresh ( );
	}

	if ( GetAttrs ( ).m_colPageBg.IsOk ( ) )
	{
		SetBackgroundColour ( GetAttrs ( ).m_colPageBg );
		Refresh ( );
	}
}

wxSizer *WidgetsPage::CreateSizerWithText ( wxControl *control, wxWindowID id, wxTextCtrl **ppText )
{
	wxSizer *sizerRow = new wxBoxSizer ( wxHORIZONTAL );
	wxTextCtrl *text = new wxTextCtrl ( this, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );

	sizerRow->Add ( control, 0, wxRIGHT | wxALIGN_CENTRE_VERTICAL, 5 );
	sizerRow->Add ( text, 1, wxLEFT | wxALIGN_CENTRE_VERTICAL, 5 );

	if ( ppText )
	{ 
		*ppText = text;
	}

	return sizerRow;
}

// create a sizer containing a label and a text ctrl
wxSizer *WidgetsPage::CreateSizerWithTextAndLabel ( const wxString& label, wxWindowID id, wxTextCtrl **ppText )
{
	return CreateSizerWithText ( new wxStaticText ( this, wxID_ANY, label ), id, ppText );
}

// create a sizer containing a button and a text ctrl
wxSizer *WidgetsPage::CreateSizerWithTextAndButton ( wxWindowID idBtn, const wxString& label, wxWindowID id, wxTextCtrl **ppText )
{
	return CreateSizerWithText ( new wxButton ( this, idBtn, label ), id, ppText );
}

wxCheckBox *WidgetsPage::CreateCheckBoxAndAddToSizer ( wxSizer *sizer, const wxString& label, wxWindowID id )
{
	wxCheckBox *checkbox = new wxCheckBox ( this, id, label );
	sizer->Add ( checkbox, 0, wxLEFT | wxRIGHT, 5 );
	sizer->Add ( 0, 2, 0, wxGROW ); // spacer

	return checkbox;
}
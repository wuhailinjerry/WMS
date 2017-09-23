#pragma once

typedef wxVector<wxWindow *> Widgets;

// struct to store common widget attributes
struct WidgetAttributes
{
	WidgetAttributes ( )
	{
#if wxUSE_TOOLTIPS
		m_tooltip = "This is a tooltip";
#endif // wxUSE_TOOLTIPS
		m_enabled = true;
		m_show = true;
		m_dir = wxLayout_LeftToRight;
		m_variant = wxWINDOW_VARIANT_NORMAL;
		m_cursor = *wxSTANDARD_CURSOR;
		m_defaultFlags = wxBORDER_DEFAULT;
	}

#if wxUSE_TOOLTIPS
	wxString m_tooltip;
#endif // wxUSE_TOOLTIPS
#if wxUSE_FONTDLG
	wxFont m_font;
#endif // wxUSE_FONTDLG
	wxColour m_colFg;
	wxColour m_colBg;
	wxColour m_colPageBg;
	bool m_enabled;
	bool m_show;
	wxLayoutDirection m_dir;
	wxWindowVariant m_variant;
	wxCursor m_cursor;
	// the default flags, currently only contains border flags
	int m_defaultFlags;
};

// ----------------------------------------------------------------------------
// dynamic WidgetsPage creation helpers
// ----------------------------------------------------------------------------

class WidgetsPage;
class WidgetsPageInfo
{
public:
	typedef WidgetsPage *(*Constructor)(wxTreebook *book, wxImageList *imaglist);

	// our ctor
	WidgetsPageInfo ( Constructor ctor, const wxChar *label, int categories );

	// accessors
	const wxString& GetLabel ( ) const
	{
		return m_label;
	}
	int GetCategories ( ) const
	{
		return m_categories;
	}
	Constructor GetCtor ( ) const
	{
		return m_ctor;
	}
	WidgetsPageInfo *GetNext ( ) const
	{
		return m_next;
	}

	void SetNext ( WidgetsPageInfo *next )
	{
		m_next = next;
	}

private:
	// the label of the page
	wxString m_label;

	// the list (flags) for sharing page between categories
	int m_categories;

	// the function to create this page
	Constructor m_ctor;

	// next node in the linked list or NULL
	WidgetsPageInfo *m_next;
};

// to declare a page, this macro must be used in the class declaration
#define DECLARE_WIDGETS_PAGE(classname)                                     \
    private:                                                                \
        static WidgetsPageInfo ms_info##classname;                          \
    public:                                                                 \
        const WidgetsPageInfo *GetPageInfo() const                          \
            { return &ms_info##classname; }

// and this one must be inserted somewhere in the source file
#define IMPLEMENT_WIDGETS_PAGE(classname, label, categories)                \
    WidgetsPage *wxCtorFor##classname(wxTreebook *book,                \
                                      wxImageList *imaglist)                \
        { return new classname(book, imaglist); }                           \
    WidgetsPageInfo classname::                                             \
        ms_info##classname(wxCtorFor##classname, label, ALL_CTRLS | categories)


class WidgetsPage : public wxPanel
{
public:
	WidgetsPage ( wxTreebook *book, wxImageList *imaglist, const char *const icon[] );

	// return the control shown by this page
	virtual wxWindow *GetWidget ( ) const = 0;

	// return the control shown by this page, if it supports text entry interface
	virtual wxTextEntryBase *GetTextEntry ( ) const
	{
		return nullptr;
	}

	// lazy creation of the content
	virtual void CreateContent ( ) = 0;

	// some pages show additional controls, in this case override this one to
	// return all of them (including the one returned by GetWidget())
	virtual Widgets GetWidgets ( ) const
	{
		Widgets widgets;
		widgets.push_back ( GetWidget ( ) );
		return widgets;
	}

	// recreate the control shown by this page
	//
	// this is currently used only to take into account the border flags
	virtual void RecreateWidget ( ) = 0;

	// apply current atrributes to the widget(s)
	void SetUpWidget ( );

	// the default attributes for the widget
	static WidgetAttributes& GetAttrs ( );

protected:
	// several helper functions for page creation

	// create a horz sizer containing the given control and the text ctrl
	// (pointer to which will be saved in the provided variable if not NULL)
	// with the specified id
	wxSizer *CreateSizerWithText ( wxControl *control,
		wxWindowID id = wxID_ANY,
		wxTextCtrl **ppText = NULL );

	// create a sizer containing a label and a text ctrl
	wxSizer *CreateSizerWithTextAndLabel ( const wxString& label,
		wxWindowID id = wxID_ANY,
		wxTextCtrl **ppText = NULL );

	// create a sizer containing a button and a text ctrl
	wxSizer *CreateSizerWithTextAndButton ( wxWindowID idBtn,
		const wxString& labelBtn,
		wxWindowID id = wxID_ANY,
		wxTextCtrl **ppText = NULL );

	// create a checkbox and add it to the sizer
	wxCheckBox *CreateCheckBoxAndAddToSizer ( wxSizer *sizer,
		const wxString& label,
		wxWindowID id = wxID_ANY );

public:
	// the head of the linked list containinginfo about all pages
	static WidgetsPageInfo *ms_widgetPages;
};


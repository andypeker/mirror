/*
ScatterChart Control
V0.6, Sept. 2007
Copyright (C) 2006-2007, Andrei-Catalin  
*/
#ifndef _Scatter_Scatter_h
#define _Scatter_Scatter_h

#include "PopUpText.h"

using namespace Upp;


typedef Pointf XY;
typedef class::Color Acolor;

class Scatter : public StaticRect {
public:
	
	enum MarkStyle 
	{
		CIRCLE,
		RECTANGLE,
		SQUARE,
		TRIANGLE,
		CROSS,
		X,
		RHOMB 
	};
	enum Formats
	{
		EXP,
		MON,
		DY,		
		CUSTOM
	};
	
	Callback3<String&, int, double> cbModifFormatX, cbModifFormatY, cbModifFormatY2;
			
	virtual void  Paint(Draw& w);
	virtual void  LeftDown(Point, dword);
	virtual void  LeftUp(Point, dword);
	virtual void  MiddleDown(Point, dword);
	virtual void  MouseMove(Point, dword);
	virtual void  MiddleUp(Point, dword);
	virtual void  MouseWheel(Point, int zdelta, dword);
	
	Callback WhenZoomScroll;
	
	Scatter& SetColor(const class::Color& _color);
	Scatter& SetTitle(const String& _title);
	Scatter& SetTitleFont(const Font& fontTitle);
	Scatter& SetTitleColor(const class::Color& colorTitle);
	
	void SetLabels(const WString& _xLabel, const WString& _yLabel, const WString& _yLabel2 = "");
	Scatter& SetLabelX(const WString& _xLabel);
	Scatter& SetLabelY(const WString& _yLabel);
	Scatter& SetLabelY2(const WString& _yLabel);
	Scatter& SetLabelsFont(const Font& fontLabels);
	Scatter& SetLabelsColor(const class::Color& colorLabels);
	
	Scatter& SetPlotAreaPoz(const int& poz_x,const int& poz_y);
	Scatter& H_Border(const int& poz_x);
	Scatter& V_Border(const int& poz_y);
	Scatter& SetPlotAreaColor(const class::Color& p_a_color);
	
	Scatter& SetAxisColor(const class::Color& axis_color);
	Scatter& SetAxisWidth(const int& axis_width);
	
	Scatter& SetGridColor(const class::Color& grid_color);
	Scatter& SetGridWidth(const int& grid_width);
	Scatter& ShowVGrid(const bool& show);
	Scatter& ShowHGrid(const bool& show);
	
	Scatter& ShowLegend(const bool& show=true);
	Scatter& SetLegendWeight(const int& weight);
	
	Scatter& SetAntialiasing(const bool& aa=true);	
	
	void SetRange(double rx, double ry, double ry2 = -1);
	double GetXRange()const {return xRange;}
	double GetYRange()const {return yRange;}
	double GetY2Range()const {return yRange2;}
	void SetMajorUnits(double ux, double uy);
	void SetMinUnits(double ux, double uy);
	void SetXYMin(double xmin,double ymin,double ymin2 = 0);
	double GetXMin () const {return xMin;}
	double GetYMin () const {return yMin;}	
	double GetYMin2 () const {return yMin2;}	
	void Graduation_FormatX(Formats fi);	
	void Graduation_FormatY(Formats fi);
	void Graduation_FormatY2(Formats fi);
	
	void SetMouseHandling(bool valx = true, bool valy = false);
	
	void AddSeries (Vector<XY> & points,const String& legend="", const bool& join=false,const class::Color& pcolor=LtBlue,const int& width=30,const int& thickness=6);
	
	inline bool IsValid(const int& j) const {return (j>=0 && j<vPointsData.GetCount());}
	
	void SetDrawXReticle(bool set = true);
	void SetDrawYReticle(bool set = true);
	void SetDrawY2Reticle(bool set = true);
	
	void SetData(const int& nbSeries, const int& index, const XY & point);
	void AddPoint(const int& nbSeries, const XY & point,const bool& refresh=true );
	void InsertPoint(const int& nbSeries, const int& index,const XY & point);
	void RemovePoint(const int& nbSeries, const int& index);
	
	void SetDataColor(const int& j,const class::Color& pcolor);
	void SetFunctColor(const int& j, const class::Color& fcolor);
	class::Color GetDataColor (const int& j) const;
	class::Color GetFunctColor (const int& j) const;	
	
	void SetDataThickness(const int& j, const int& thick_dots);
	void SetFunctThickness(const int& j,const int& thick_dots);
	int GetDataThickness(const int& j) const;
	int GetFunctThickness(const int& j) const;
	void SetMarkWidth(const int& j, const int& width_dots);
	int GetMarkWidth(const int& j) const;
	void SetMarkStyle(const int& j, MarkStyle noStyle);
	int GetMarkStyle(const int& j) const;
	void SetMarkColor(const int& j, const class::Color& pcolor);
	Acolor GetMarkColor (const int& j) const;
	void SetShowMark(const int& j, const bool& show=true);
	bool IsMarkShow(const int& j) const throw (Exc);
	
	void SetJoin(const int& j, const bool& join=true);
	bool IsJoined(const int& j) const throw (Exc);
	
	void SetSmooth(const int& j, const bool& smooth=true);
	bool IsSmooth(const int& j) const throw (Exc);	
	
	void SetDataPrimaryY(const int& j, const bool& primary=true);
	bool IsDataPrimaryY(const int& j) const throw (Exc);	
	void SetFunctPrimaryY(const int& j, const bool& primary=true);
	bool IsFunctPrimaryY(const int& j) const throw (Exc);	
	
	void RemoveSeries(const int& j);
	void RemoveAllSeries();
	void SetData(const int& nbSeries, Vector<XY> & points);	
	const Vector<Vector<XY> > & GetPData() const {return vPointsData;}
	const Vector<Vector<XY> > & GetFData() const {return vFunctionData;}
	
	const Vector<String> & GetPLegend() const {return vLegend;}
	const Vector<String> & GetFLegend() const {return vFLegend;}		
	
	void PlotFunction(double (*f)(double),const String& legend="", const class::Color& fcolor=Green,const int& weight=6);
	void PlotParaFunction(XY (*pf)(double),const String& legend="", const class::Color& fcolor=Green,const int& weight=6,const int& Np=100);
	void RemoveFSeries(const int& j);
	void RemoveAllFSeries();
	
	void ShowInfo(bool show=true);	
	
	Drawing GetDrawing()const;
	Image GetImage(const int& scale=1);
	
	#ifdef PLATFORM_WIN32
	void SaveAsMetafile(const char* file)const;
	#endif
	
	void SaveToClipboard();
	
	Scatter& LogX(const bool& logx=true) {logX=logx; return *this;}
	Scatter& LogY(const bool& logy=true) {logY=logy; return *this;}	
	Scatter& LogY2(const bool& logy=true) {logY2=logy; return *this;}	

private:
	class ::Color graphColor;	
	String title;
	Font titleFont;
	class::Color titleColor;
	
	WString xLabel, yLabel, yLabel2;
	Font labelsFont;
	class::Color labelsColor;
	
	int px, py;
	class ::Color plotAreaColor;
	
	bool paintInfo;
	Point clickPoint;
	PopUpInfo popText;
	const Point offset;
	
	class::Color axisColor;
	int axisWidth;
	
	double xRange,yRange,yRange2;
	double xMin,yMin,yMin2;
	double xMajorUnit,yMajorUnit,yMajorUnit2;
	double xMinUnit,yMinUnit, yMinUnit2;
	bool drawXReticle, drawYReticle, drawY2Reticle;	
	
	class::Color gridColor;
	int gridWidth;
	bool drawVGrid, drawHGrid;	
	
	bool logX, logY, logY2;	
	
	int butDownX, butDownY;
	bool isButDown;
	
	Vector<Vector<XY> > vPointsData,vFunctionData;
	Vector<bool> vFPrimaryY, vPPrimaryY;
	typedef double (*fAdress)(double);
	Vector<fAdress> vAdress;
	Vector<class::Color> vPColors,vFColors;
	Vector<int> vFThickness,vPThickness;
	Vector<int> vPWidth;
	Vector<bool> vJoin;
	Vector<bool> vSmooth;
	Vector<class::Color> vMarkColors;
	Vector<bool> vShowMark;
	Vector<int> vMarkStyles;
	
	Vector<String> vLegend;
	Vector<String> vFLegend;
	bool showLegend;
	int legendWeight;
	bool antialiasing;
	bool mouseHandlingX, mouseHandlingY;
	
	Vector<XY> Cubic (const Vector<XY>& DataSet, const int& fineness=10, double tension=0.4)const;
	void DrawLegend(Draw& w,const int& scale) const;
	
	void SetDrawing(Draw& w, const int& scale)const;
	void Circle(Draw& w, const int& scale, const Point& cp, const int& size, const class::Color& markColor)const;
	void Square(Draw& w, const int& scale, const Point& cp, const int& size, const class::Color& markColor)const;
	void Rectangle(Draw& w, const int& scale, const Point& cp, const int& size, const class::Color& markColor)const;
	void Triangle(Draw& w, const int& scale, const Point& cp, const int& size, const class::Color& markColor)const;
	void Cross(Draw& w, const int& scale, const Point& cp, const int& size, const class::Color& markColor)const;
	void XFunct(Draw& w, const int& scale, const Point& cp, const int& size, const class::Color& markColor)const;
	void Rhomb(Draw& w, const int& scale, const Point& cp, const int& size, const class::Color& markColor)const;
	inline void DrawMark(const int& style, Draw& w, const int& scale, const Point& cp, const int& size, const class::Color& markColor)const;
	
	virtual Image  CursorImage(Point p, dword keyflags);
	
	void ExpFormat(String& s, int i, double d)
	{
		s=FormatDoubleExp(d,1);
	}
	void MonFormat(String& s, int i, double d)
	{
		s=Format("%Mon",int(d));
	}
	void DyFormat(String& s, int i, double d)
	{
		s=Format("%Dy",int(d));
	}
	
	static String VariableFormat(double range, double d)
	{
		if (fabs(d) <= 1e-15)
			d = 0;
		if 		(0.001<=range && range<0.01) 	return FormatDouble(d,5);
		else if (0.01<=range && range<0.1) 		return FormatDouble(d,4);
		else if (0.1<=range && range<1) 		return FormatDouble(d,3);
		else if (1<=range && range<10) 			return FormatDouble(d,2);
		else if (10<=range && range<100) 		return FormatDouble(d,1);
		else if (100<=range && range<100000) 	return FormatDouble(d,0);
		else return FormatDoubleExp(d,2);
		
	}	
	String VariableFormatX(const double& d) const  {return VariableFormat(xRange, d);}
	String VariableFormatY(const double& d) const  {return VariableFormat(yRange, d);} 
	String VariableFormatY2(const double& d) const {return VariableFormat(yRange2, d);}
	
	void Plot(Draw& w, const int& scale,const int& l,const int& h) const;		

public:
	typedef Scatter CLASSNAME;
	Scatter();
	~Scatter();
};


#endif


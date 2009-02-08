// This file is part of wkhtmltopdf.
//
// wkhtmltopdf is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// wkhtmltopdf is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with wkhtmltopdf.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __wkhtmltopdf_hh__
#define __wkhtmltopdf_hh__
#include <QObject>
#include <QtGui>
#include <QWebView>
#include <QNetworkProxy>
#include <stdlib.h>

//Class responsible for the convertion
class WKHtmlToPdf : public QObject {
	Q_OBJECT
public:
	//The webview is used to fetch and render the webpage using webkit
	QWebPage page;

	//Configuration variabels
	const char * in; //Name of the input file
	const char * out; //Name of the output file
	QNetworkProxy::ProxyType proxyType; //Type of proxy to use
	int proxyPort; //The port of the proxy to use
	const char * proxyHost; //The host name of the proxy to use or NULL
	const char * proxyUser; //Username for the said broxy or NULL
	const char * proxyPassword; //Password for the said broxy or NULL
	bool quiet; //Be less verbose
	bool background; //Should we print the background?
	QPrinter::PageSize pageSize; //What size paper should we use
	QPrinter::Orientation orientation; //What orientation
	QPrinter::ColorMode colorMode; //Color or grayscale
	QPrinter::PrinterMode resolution; //resolution
	int dpi;
	std::pair<qreal, QPrinter::Unit> top;
	std::pair<qreal, QPrinter::Unit> right;
	std::pair<qreal, QPrinter::Unit> bottom;
	std::pair<qreal, QPrinter::Unit> left;
	
	std::pair<qreal, QPrinter::Unit> parseUnitReal(const char * o);
	static QUrl guessUrlFromString(const QString &string);
	void version(FILE * fd); //Print version information to fd
	void usage(FILE * fd); //Print usage information to fd
	void setPageSize(const char * size);
	void setOrientation(const char * orientation);
	void setProxy(const char * proxy); //parse proxy configuartion
	int parseLongArg(const char * arg, int morec, const char ** morev);
	void parseArgs(int argc, const char** argv); //Prase arguments
	void run(int argc, const char** argv);

public slots:
	void loadFinished(bool ok);
	void loadProgress(int progress);
	void sslErrors(QNetworkReply *reply, const QList<QSslError> &error);
};
#endif //__wkhtmltopdf_hh__

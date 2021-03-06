#ifndef GIFURLEXTRACTOR_H
#define GIFURLEXTRACTOR_H

#include <QObject>
#include <QUrl>

class QWebFrame;
class Site;
class GifUrlExtractor : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(GifUrlExtractor)
public:
    explicit GifUrlExtractor(QObject *parent = 0);
    void setUrl(const QUrl& url);

public slots:
    void start();

signals:
    void finished();
    void urlsReady(const QList<QString>& urls);

private slots:
    void onPageLoaded(bool load);

private:
    QString extractLink(const QString& rawStr);

private:
    QUrl m_url;
    QWebFrame* m_webFrame;
};

#endif // GIFURLEXTRACTOR_H

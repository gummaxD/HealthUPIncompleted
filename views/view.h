#ifndef VIEW_H
#define VIEW_H

#include <QWidget>

class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(View *parent = nullptr);
    //explicit View(const QString& t, QWidget *parent = nullptr);

    void setTitolo(const QString& t);
    virtual ~View();

protected:
    virtual void connettiSignals()const = 0;


signals:

public slots:
};

#endif // VIEW_H

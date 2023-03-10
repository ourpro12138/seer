#ifndef POKEDEX_H
#define POKEDEX_H

#include <QWidget>
#include "pdbackpushbutton.h"
#include <QPainter>

namespace Ui {
class pokedex;
}

class pokedex : public QWidget
{
    Q_OBJECT

public:
    explicit pokedex(QWidget *parent = nullptr);
    ~pokedex();
    void paintEvent(QPaintEvent *);

private slots:

    void on_pushButtonfire_clicked();

    void on_pushButtonwater_clicked();

    void on_pushButtongrass_clicked();

    void on_pushButtonnormal_clicked();

    void on_pushButtonfirem_clicked();

    void on_pushButtonfireh_clicked();

    void on_pushButtonfirex_clicked();

    void on_pushButtonfirej_clicked();

    void on_pushButtonfirel_clicked();

    void on_pushButtonfireljls_clicked();

    void on_pushButtonwateryy_clicked();


    void on_pushButtonfirehly_clicked();

    void on_pushButtonfirelos_clicked();

    void on_pushButtondierk_clicked();

    void on_pushButtonfiredierk_clicked();

    void on_pushButtonbubu_clicked();

    void on_pushButtonguru_clicked();

    void on_pushButtonyourian_clicked();

    void on_pushButtonbarus_clicked();

    void on_pushButtonbara_clicked();

    void on_pushButtonjieni_clicked();

    void on_pushButtonbaragui_clicked();

    void on_pushButtonyaya_clicked();

    void on_pushButtonyayaa_clicked();

    void on_pushButtonsyaya_clicked();

    void on_pushButtonbbl_clicked();

    void on_pushButtonfishdrgon_clicked();

    void on_pushButtonking_clicked();

    void on_pushButtonbubucao_clicked();

    void on_pushButtonbubuhua_clicked();

    void on_pushButtonxiaodouya_clicked();

    void on_pushButtondingding_clicked();

    void on_pushButtonmohua_clicked();

    void on_pushButtonxrq_clicked();

    void on_pushButtonxrh_clicked();

    void on_pushButtonxrz_clicked();

    void on_pushButtonyiyi_clicked();

    void on_pushButtonyidingsi_clicked();

    void on_pushButtonyika_clicked();

    void on_pushButtonguruking_clicked();

    void on_pushButtonxinke_clicked();

    void on_pushButtonxinnasi_clicked();

    void on_pushButtonagong_clicked();

    void on_pushButtonbobo_clicked();

    void on_pushButtonaoligong_clicked();

    void on_pushButtontaida_clicked();

    void on_pushButtontailesi_clicked();

signals:
    void back();
private:
    Ui::pokedex *ui;
};

#endif // POKEDEX_H

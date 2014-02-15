#ifndef CHOIXTYPEJOUEUR_H
#define CHOIXTYPEJOUEUR_H

#include "joueur.h"
#include "joueuriaintelligent.h"
#include "joueurIArandom.h"
#include "joueurhumaingui.h"

#include <memory>
#include <QRadioButton>
#include <QWidget>

class ChoixTypeJoueur : public QWidget
{
    Q_OBJECT
public:
    explicit ChoixTypeJoueur(const QString & text, QWidget *parent = 0);

    //reset le pointeur "joueur" avec un objet du type approprié
    // (en fonction de quels boutons radios sont cochés).
    void initTypeJoueur(std::unique_ptr<Joueur> &joueur);
signals:

public slots:

private:
    QRadioButton *joueurHumain;
    QRadioButton *joueurIaRandom;

};

#endif // CHOIXTYPEJOUEUR_H

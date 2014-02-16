#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include "choixtypejoueur.h"
#include "grillejeugraphique.h"
#include "jeu.h"

#include <memory>

#include <QPushButton>
#include <QGridLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QWidget>

class FenetrePrincipale : public QWidget
{
    Q_OBJECT
public:

    explicit FenetrePrincipale(QWidget *parent = 0);

signals:
public slots:
    void boutonNouveauJeuClique();

private:
    std::unique_ptr<Jeu> m_jeu;
    std::unique_ptr<Joueur> m_joueur1;
    std::unique_ptr<Joueur> m_joueur2;

    GrilleJeuGraphique m_grille;
    QPushButton m_boutonNouveauJeu;

    ChoixTypeJoueur m_choixTypeJoueur1;
    ChoixTypeJoueur m_choixTypeJoueur2;

    QGridLayout layoutPrincipal;
};

#endif // FENETREPRINCIPALE_H

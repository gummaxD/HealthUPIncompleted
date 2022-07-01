#include "calendarview.h"

CalendarView::CalendarView(View* parent)
    : View (parent),
      mainLayout (new QVBoxLayout),
      barraMenu(new QMenuBar(this)),
      menuFile (new QMenu("FILE",barraMenu)),
      apri (new QAction("Apri",menuFile)),
      salva(new QAction("Salva",menuFile)),
      menuGrafici(new QMenu("GRAFICI",barraMenu)),
      grafico1(new QAction("Grafico1",menuGrafici)),
      grafico2(new QAction("Grafico2",menuGrafici)),
      grafico3(new QAction("Grafico3",menuGrafici)),
      calendario(new QCalendarWidget(this)),
      GPcolazione(new QGroupBox("Colazione",this)),
      GPpranzo(new QGroupBox("Pranzo",this)),
      GPcena(new QGroupBox("Cena",this)),
      GPaggiungiPasto(new QGroupBox("Pasto",this)),
      CBpiatto(new QComboBox(this)),
      SBgrammi(new QSpinBox(this)),
      CBtipo(new QComboBox(this)),
      TWcolazione(new QTableWidget(this)),
      TWpranzo(new QTableWidget(this)),
      TWcena(new QTableWidget(this)),
      PBAggiungi(new QPushButton("+",this))
{
    // aggiungo il menu alla barra dei menu
    barraMenu->addMenu(menuFile);
    barraMenu->addMenu(menuGrafici);

    // aggiungo le  actions
    menuFile->addAction(apri);
    menuFile->addAction(salva);
    menuGrafici->addAction(grafico1);
    menuGrafici->addAction(grafico2);
    menuGrafici->addAction(grafico3);

    //modifiche al calendario
    calendario->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);
    QDate min (2000,1,1);
    calendario->setMinimumDate(min);

    //modifiche alla combobox tipo
    CBtipo->addItem("COLAZIONE");
    CBtipo->addItem("PRANZO");
    CBtipo->addItem("CENA");

    /*       ------------------------
     *       |                       |    <--- sopra
     *       -------------------------
     *       |           |           |
     *       |           |           |    <---- sotto
     *       |           |           |
     *       |           |           |
     *        ------------------------
     *         ^               ^
     *         |               |
     *        left            right
     */

    QVBoxLayout* sopra = new QVBoxLayout();
    QHBoxLayout* sotto = new QHBoxLayout();

    QVBoxLayout* left = new QVBoxLayout();
    QVBoxLayout* right = new QVBoxLayout();

    QHBoxLayout* GBpiattoLayout = new QHBoxLayout();

    QVBoxLayout* GBcolazioneLayout = new QVBoxLayout();
    QVBoxLayout* GBpranzoLayout = new QVBoxLayout();
    QVBoxLayout* GBcenaLayout = new QVBoxLayout();

    layouts.push_back(sopra);
    layouts.push_back(sotto);
    layouts.push_back(left);
    layouts.push_back(right);
    layouts.push_back(GBpiattoLayout);
    layouts.push_back(GBcolazioneLayout);
    layouts.push_back(GBpranzoLayout);
    layouts.push_back(GBcenaLayout);

    GBcolazioneLayout->addWidget(TWcolazione);
    GBpranzoLayout->addWidget(TWpranzo);
    GBcenaLayout->addWidget(TWcena);

    // setto i layout ai group box di sotto/sx
    GPcolazione->setLayout(GBcolazioneLayout);
    GPpranzo->setLayout(GBpranzoLayout);
    GPcena->setLayout(GBcenaLayout);

    // aggiungo al main layout quello sopra e quello sotto
    mainLayout->addLayout(sopra);
    mainLayout->addLayout(sotto);

    // aggiungo il menu al layout sopra
    sopra->addWidget(barraMenu);


    //aggiungo layout left e right al layout sotto
    sotto->addLayout(left);
    sotto->addLayout(right);

    // modifiche layout sotto sx
    left->addWidget(calendario);
    left->addWidget(GPcolazione);
    left->addWidget(GPpranzo);
    left->addWidget(GPcena);

    //modifiche al p
    right->addSpacing(400);
    right->addWidget(GPaggiungiPasto);


    // modifiche layout per il groupBox Piatto
    GBpiattoLayout->addWidget(CBpiatto);
    GBpiattoLayout->addWidget(SBgrammi);
    GBpiattoLayout->addWidget(CBtipo);
    GBpiattoLayout->addWidget(PBAggiungi);

    GPaggiungiPasto->setLayout(GBpiattoLayout);
    setLayout(mainLayout);

    connettiSignals();
}

void CalendarView::connettiSignals()const{

}

CalendarView::~CalendarView(){
    for (auto it : layouts)
        delete it;
}

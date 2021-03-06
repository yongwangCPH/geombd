#ifndef Session_h_
#define Session_h_

#include "Main.h"

class Model;
class Body;
class BindingCriteria;

 
class Session {
  friend class Model;

  protected:
    int id;
    Model *model;
    SimulationConfig type;
    int Nreplicates;
    cilk::reducer< cilk::op_add<int> > Nbind;
    cilk::reducer< cilk::op_add<int> > Nexit;
    cilk::reducer< cilk::op_add<int> > Ntlim;
    cilk::reducer< cilk::op_add<double> > t_avgt;
    double Davg;
    vector< Body* > conformations;
    vector< Body* > ligands;
    vector< BindingCriteria* > bindingCriteria;
    deque<double> beta_history;
    bool done;

  public:
    Session(Model *m, SimulationConfig s);
    ~Session();

    virtual void populateLigands();
    virtual void positionLigand(Body *body) { };
    virtual void printRateConstant() { };
    virtual void checkLigand(Body *body) { };
    virtual void recordBeta();
    virtual double checkConvergence();
    virtual void finalize() { };

};


class SessionNAM : public Session {
  friend class Model;
  protected:
    double b;
    double q, q2;

  public:
    SessionNAM(Model *m);

    virtual void positionLigand(Body *body);
    virtual void printRateConstant();
    virtual void checkLigand(Body *body);

};


class SessionDirect : public Session {
  friend class Model;
  protected:
    vertex start;
    double b;
    double q, q2;

  public:
    SessionDirect(Model *m);

    virtual void positionLigand(Body *body);
    virtual void printRateConstant();
    virtual void checkLigand(Body *body);

};


#endif

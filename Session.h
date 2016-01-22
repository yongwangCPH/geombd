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

  public:
    Session(Model *m, SimulationConfig s);
    ~Session();

    virtual void populateLigands();
    virtual void positionLigand(Body *body);
    virtual void printRateConstant();
    virtual void checkLigand(Body *body) { };

};


class SessionRadial : public Session {
  friend class Model;
  protected:
    double b;
    double q, q2;

  public:
    SessionRadial(Model *m);

    virtual void positionLigand(Body *body);
    virtual void printRateConstant();
    virtual void checkLigand(Body *body);

};


class SessionAbsolutePeriodic : public Session {
  friend class Model;
  protected:
    vertex start;
    vertex bounds;
    double b;
    double t_max;

  public:
    SessionAbsolutePeriodic(Model *m);

    virtual void positionLigand(Body *body);
    virtual void printRateConstant();
    virtual void checkLigand(Body *body);

};


class SessionAbsoluteRadial : public Session {
  friend class Model;
  protected:
    vertex start;
    double b;
    double q, q2;

  public:
    SessionAbsoluteRadial(Model *m);

    virtual void positionLigand(Body *body);
    virtual void printRateConstant();
    virtual void checkLigand(Body *body);

};


class MilestoneState {
  public:
    MilestoneState() {
      r0 = 0.;
    }
    MilestoneState(double r00) {
      r0 = r00;
      cout << r0 << endl;
    }

    double r0;
    cilk::reducer< cilk::op_list_append<double> > tfwd;
    cilk::reducer< cilk::op_list_append<double> > tbck;

};


class SessionMilestone : public Session {
  friend class Model;
  protected:
    vector<MilestoneState*> states;
    MilestoneState *state;
    double reaction;
    double spacing;

  public:
    SessionMilestone(Model *m);

    virtual void positionLigand(Body *body);
    virtual void printRateConstant();
    virtual void checkLigand(Body *body);

};


#endif

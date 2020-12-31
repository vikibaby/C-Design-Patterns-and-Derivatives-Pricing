#ifndef PARAMETERS_H
#define PARAMETERS_H

class ParametersInner
{
public:
  ParametersInner(){}
  virtual ParametersInner* clone()const= 0;
  virtual double Intergal(double time1, double time2) const = 0;
  virtual double IntergalSquare(double time1, double time2) const = 0;
  virtual ~ParametersInner(){}
private:
};


class Parameters
{
public:
  Parameters(const ParametersInner& innerObject);
  Parameters(const Parameters& original);
  Parameters& operator = (const Parameters& original);
  virtual ~Parameters();

  inline double Intergal(double time1, double time2) const ;
  inline double IntergalSquare(double time1, double time2) const;

  double Mean(double time1, double time2) const;
  double RootMeanSquare(double time1, double time2) const;

private:
  ParametersInner* InnerObjectPtr;
};

inline double Parameters::Intergal(double time1, double time2) const
{
  return InnerObjectPtr->Intergal(time1,time2);
}

inline double Parameters::IntergalSquare(double time1, double time2) const
{
  return InnerObjectPtr->IntergalSquare(time1,time2);
}

class ParametersConstant:public ParametersInner
{
public:
  ParametersConstant(double constant);
  virtual ParametersInner* clone()const;
  inline double Intergal(double time1, double time2) const ;
  inline double IntergalSquare(double time1, double time2) const;

private:
  double Constant;
  double ConstantSquare;
};
#endif

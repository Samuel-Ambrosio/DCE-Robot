void ForwardMotorD()
{  
  digitalWrite(Pin1_motorD,LOW); 
  digitalWrite(Pin2_motorD,HIGH);
}

void ForwardMotorI()
{  
  digitalWrite(Pin1_motorI,LOW); 
  digitalWrite(Pin2_motorI,HIGH);
}

void ReverseMotorD()
{
  digitalWrite(Pin1_motorD,HIGH);
  digitalWrite(Pin2_motorD,LOW);
}

void ReverseMotorI()
{
  digitalWrite(Pin1_motorI,HIGH);
  digitalWrite(Pin2_motorI,LOW);
}

void StopD()
{
  digitalWrite(Pin1_motorD,LOW);
  digitalWrite(Pin2_motorD,LOW);
}

void StopI()
{
  digitalWrite(Pin1_motorI,LOW);
  digitalWrite(Pin2_motorI,LOW);
}

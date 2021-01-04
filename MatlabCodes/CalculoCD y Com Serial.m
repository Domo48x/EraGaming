clc
clear all
close all
%%% Este ejemplo simula un manipulador de dos brazos con dos articulaciones rotacionales

%%% Especificar parámetros para obtener matrices de transformación
%Se realizó con nuestro examen 1 como ejemplo

%Denavit Hartenberg p/brazo 1
a1 = 0; alpha1 = 0; d1=4; theta1 = 10.8;
H01 = DH(a1,alpha1,d1,theta1); %H^0_1

%Denavit Hartenberg p/brazo 2
a2 = 4; alpha2 = 0; d2=4; theta2 = 10.8;
H12 = DH(a2,alpha2,d2,theta2); %H^1_2

%Denavit Hartenberg p/brazo 3
a3 = 4; alpha3 = 0; d2=4; theta3 = 10.8;
H13 = DH(a3,alpha3,d3,theta3); %H^1_2

%Denavit Hartenberg p/brazo 4
a4 = 4; alpha4 = 0; d2=4; theta4 = 10.8;
H14 = DH(a4,alpha4,d4,theta4); %H^1_2

%Denavit Hartenberg p/brazo 5
a5 = 4; alpha2 = 0; d2=4; theta5 = 10.8;
H15 = DH(a5,alpha5,d5,theta5); %H^1_2

%Imprimir multiplicación de matrices
display(H01*H12*H13*H14*H15);

%Definimos el dispositivo de comunicación serial
device = serialport("COM3", 9600);

%Definimos la cadena de información 
data = num2str(theta1) + "/" + num2str(theta2) + "/" + num2str(theta3) + "/" + num2str(theta4) + "/" + num2str(theta5);

%sacamos la información por el dispositivo previamente definido
write(device, data, "string");

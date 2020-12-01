clc
clear all
close all
%%% Este ejemplo simula un manipulador de dos brazos con dos articulaciones rotacionales

%%% Especificar parámetros para obtener matrices de transformación
%Se realizó con nuestro examen 1 como ejemplo

%Denavit Hartenberg p/brazo 1
a1 = 0; alpha1 = 0; d1=4; theta1 = 10.8;
H01 = PF(a1,alpha1,d1,theta1); %H^0_1

%Denavit Hartenberg p/brazo 2
a2 = 4; alpha2 = 0; d2=4; theta2 = 10.8;
H12 = PF(a2,alpha2,d2,theta2); %H^1_2

%Imprimir multiplicación de matrices
display(H01*H12);
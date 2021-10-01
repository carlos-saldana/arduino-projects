package com.example.robotcar;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;

import com.example.hp.bluetoothjhr.BluetoothJhr;

public class Main2Activity extends AppCompatActivity {

    //---------- Variable para la comunicación Bluetooth ----------
    BluetoothJhr bluetoothJhr;

    //---------- Variables a emplear ----------
    ImageButton btn_up, btn_down, btn_left, btn_rigth, btn_stop;
    Button btn_act_aut;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        //---------- Asignación de componentes ----------
        btn_up = findViewById(R.id.btn_up);
        btn_down = findViewById(R.id.btn_down);
        btn_left = findViewById(R.id.btn_left);
        btn_rigth = findViewById(R.id.btn_rigth);
        btn_stop = findViewById(R.id.btn_stop);

        btn_act_aut = findViewById(R.id.btn_act_aut);

        //---------- Comunicación con el primer MainActivity ----------
        bluetoothJhr = new BluetoothJhr(Main2Activity.class, this);

        //---------- Funciones ----------

        btn_up.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bluetoothJhr.Tx("a");
            }
        });

        btn_down.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bluetoothJhr.Tx("b");
            }
        });

        btn_left.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bluetoothJhr.Tx("c");
            }
        });

        btn_rigth.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bluetoothJhr.Tx("d");
            }
        });

        btn_stop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bluetoothJhr.Tx("e");
            }
        });

        btn_act_aut.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                bluetoothJhr.Tx("f");

            }
        });

    }

    //---------- Conexión Bluetooth ----------
    @Override
    public void onResume(){
        super.onResume();
        bluetoothJhr.ConectaBluetooth();
    }
    //----------------------------------------

    //---------- Desconexión Bluetooth ----------
    @Override
    public void onPause(){
        super.onPause();
        bluetoothJhr.CierraConexion();
    }
    //-------------------------------------------
}

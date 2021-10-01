package com.example.robotcar;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;

import com.example.hp.bluetoothjhr.BluetoothJhr;

public class MainActivity extends AppCompatActivity {

    //---------- Lista de dispositivos Bluetooth ----------
    ListView Dispositivos;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //---------- Enlazamos nuestra variable del archivo .xml y .java ----------
        Dispositivos = findViewById(R.id.Dispositivos);

        //---------- Llamamos a la librería Bluetooth ----------
        final BluetoothJhr bluetoothJhr = new BluetoothJhr(this, Dispositivos);
        bluetoothJhr.EncenderBluetooth(); //---------- Activamos Bluetooth ----------

        //------------------------------ Conexión Bluetooth ------------------------------
        Dispositivos.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                bluetoothJhr.Disp_Seleccionado(view, i, Main2Activity.class);
            }
        });
    }
}

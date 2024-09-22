/*
 * Copyright (c) 2016 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.lineageos.settings.display;

import android.app.Service;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.IBinder;
import android.os.SystemProperties;
import android.util.Log;

public class LcdFeaturesService extends Service {
    private static final String TAG = "LcdFeaturesService";
    private static final boolean DEBUG = false;
    private String lastCABC;
    private String lastHBM;

    @Override
    public void onCreate() {
        if (DEBUG) Log.d(TAG, "Creating service");
        IntentFilter screenStateFilter = new IntentFilter(Intent.ACTION_SCREEN_ON);
        screenStateFilter.addAction(Intent.ACTION_SCREEN_OFF);
        registerReceiver(mScreenStateReceiver, screenStateFilter);
        lastHBM = SystemProperties.get(LcdFeaturesPreferenceFragment.HBM_PROP, "0");
        lastCABC = SystemProperties.get(LcdFeaturesPreferenceFragment.CABC_PROP, "0");
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        if (DEBUG) Log.d(TAG, "Starting service");
        return START_STICKY;
    }

    @Override
    public void onDestroy() {
        if (DEBUG) Log.d(TAG, "Destroying service");
        super.onDestroy();
        this.unregisterReceiver(mScreenStateReceiver);
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    private void onDisplayOn() {
        if (DEBUG) Log.d(TAG, "Display on");
        SystemProperties.set(LcdFeaturesPreferenceFragment.HBM_PROP, lastHBM);
        SystemProperties.set(LcdFeaturesPreferenceFragment.CABC_PROP, lastCABC);
    }

    private void onDisplayOff() {
        if (DEBUG) Log.d(TAG, "Display off");
        lastHBM = SystemProperties.get(LcdFeaturesPreferenceFragment.HBM_PROP, "0");
        lastCABC = SystemProperties.get(LcdFeaturesPreferenceFragment.CABC_PROP, "0");
    }

    private BroadcastReceiver mScreenStateReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            if (intent.getAction().equals(Intent.ACTION_SCREEN_ON)) {
                onDisplayOn();
            } else if (intent.getAction().equals(Intent.ACTION_SCREEN_OFF)) {
                onDisplayOff();
            }
        }
    };
}

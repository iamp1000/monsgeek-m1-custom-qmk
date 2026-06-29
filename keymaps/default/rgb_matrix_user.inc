RGB_MATRIX_EFFECT(AURORA_BOREALIS)
RGB_MATRIX_EFFECT(LIQUID_MERCURY)
RGB_MATRIX_EFFECT(SAKURA_BLOOM)
RGB_MATRIX_EFFECT(EVENT_HORIZON)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// 1. Aurora Borealis (Slow green/cyan/purple wave)
static bool AURORA_BOREALIS(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    // Increased the multiplier significantly so the wave moves visibly
    uint16_t time = (g_rgb_timer * rgb_matrix_config.speed) / 32;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint8_t x = g_led_config.point[i].x;
        uint8_t y = g_led_config.point[i].y;
        
        // slow sine wave spanning green (85) to purple (190)
        uint8_t val = sin8(time / 256 + x + (y >> 1));
        uint8_t hue = 85 + scale8(val, 105); 
        
        HSV hsv = {hue, 255, rgb_matrix_config.hsv.v};
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}

// 2. Liquid Mercury (Silver/grayscale flow)
static bool LIQUID_MERCURY(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    // Faster ripple effect
    uint16_t time = (g_rgb_timer * rgb_matrix_config.speed) / 16;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint8_t x = g_led_config.point[i].x;
        uint8_t y = g_led_config.point[i].y;
        
        uint8_t val = sin8(time / 128 + x*2 + y*2);
        uint8_t v = scale8(val, rgb_matrix_config.hsv.v);
        
        // 0 saturation = grayscale/silver
        HSV hsv = {0, 0, v}; 
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}

// 3. Sakura Bloom (Reactive pink/white expanding circle)
static bool SAKURA_BLOOM(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        
        uint16_t max_val = 0;
        uint8_t x = g_led_config.point[i].x;
        uint8_t y = g_led_config.point[i].y;
        
#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
        for (uint8_t j = 0; j < g_last_hit_tracker.count; j++) {
            int16_t dx = x - g_last_hit_tracker.x[j];
            int16_t dy = y - g_last_hit_tracker.y[j];
            
            // Approximation of distance to save sqrt cycles
            uint8_t dist = (abs(dx) + abs(dy));
            uint16_t tick = timer_elapsed(g_last_hit_tracker.tick[j]);
            
            int16_t diff = tick - (dist * 4); // increased spread distance delay
            if (diff > 0 && diff < 255) {
                // Blooms outwards slowly and fades slowly
                uint16_t val = 255 - diff;
                if (val > max_val) max_val = val;
            }
        }
#endif
        
        // Sakura Pink Hue is around 235
        HSV hsv = {235, 160, scale8(max_val, rgb_matrix_config.hsv.v)};
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}

// 4. Event Horizon (Dark center, purple ripples)
static bool EVENT_HORIZON(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint16_t time = (g_rgb_timer * rgb_matrix_config.speed) / 24;
    
    uint8_t center_x = 112; 
    uint8_t center_y = 32;
    
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint8_t x = g_led_config.point[i].x;
        uint8_t y = g_led_config.point[i].y;
        
        int16_t dx = x - center_x;
        int16_t dy = y - center_y;
        uint8_t dist = (abs(dx) + abs(dy)); 
        
        if (dist < 30) {
            rgb_matrix_set_color(i, 0, 0, 0);
            continue;
        }
        
        uint8_t val = sin8(time / 64 - dist * 2);
        uint8_t v = scale8(val, rgb_matrix_config.hsv.v);
        
        if (dist < 50) {
             v = scale8(v, (dist - 30) * 12); 
        }
        
        HSV hsv = {190, 255, v};
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/pwm.h"

// Valores para PWM de frequência 50Hz e 20ms de período
#define CLK_DIV 125.0f
#define WRAP 20000

// Ciclos ativos referente ao período de 20ms em us
#define GRAU_0 500
#define GRAU_90 1470
#define GRAU_180 2400

// Variáveis de velocidade da movimentação periódica do servo motor
#define SERVO_STEP 5
#define STEP_DELAY 10

// Armazenam ângulo atual e sentido da movimentação periódica
static volatile bool sentidoHorario = true;
static volatile uint grauAtual = GRAU_0;

// Pino e slice PWM do servo motor
const uint motor_pwm_pin = 22;
static uint slice;

// Header de função
void inicializarPWM();

int main()
{   
    // Garantir clock 125mHz para facilitar divisão e inicializar PWM no pino do servo motor
    set_sys_clock_khz(125000, true);
    inicializarPWM();

    stdio_init_all();

    // Posicionar servo motor nos ângulos 180*, 90* e 0* em intervalos de 5 segundos
    pwm_set_chan_level(slice, PWM_CHAN_A, GRAU_180);
    sleep_ms(5000);
    pwm_set_chan_level(slice, PWM_CHAN_A, GRAU_90);
    sleep_ms(5000);
    pwm_set_chan_level(slice, PWM_CHAN_A, GRAU_0);
    sleep_ms(5000);

    // Começar movimentação periódica do servo motor
    while (true) 
    {   
        // Definir novo ângulo para o servo motor
        pwm_set_chan_level(slice, PWM_CHAN_A, grauAtual);

        // Mover levemente no sentido estabelecido
        if (sentidoHorario)
        {   
            grauAtual += SERVO_STEP;
            if (grauAtual >= GRAU_180) // Limite de 180 graus para sentido horário
            {
                grauAtual = GRAU_180;
                sentidoHorario = false;
            }
        }
        else
        {
            grauAtual -= SERVO_STEP;
            if (grauAtual <= GRAU_0) // Limite de 0 graus para sentido anti-horário
            {
                grauAtual = GRAU_0;
                sentidoHorario = true;
            }
        }
        sleep_ms(STEP_DELAY);
    }
}

// Inicializa adequadamente o PWM para controle do servo motor
void inicializarPWM()
{   
    // Definir pino e obter o slice
    gpio_set_function(motor_pwm_pin, GPIO_FUNC_PWM);
    slice = pwm_gpio_to_slice_num(motor_pwm_pin);

    // Divisor de clock e wrap
    pwm_set_clkdiv(slice, CLK_DIV);
    pwm_set_wrap(slice, WRAP);

    // Ativar PWM
    pwm_set_enabled(slice, true);
}

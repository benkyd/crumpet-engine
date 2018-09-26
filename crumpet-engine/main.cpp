#include <assert.h>

#include <allegro5\allegro.h>

int main(void *) {
	ALLEGRO_DISPLAY * display;
	ALLEGRO_EVENT_QUEUE * queue;
	ALLEGRO_BITMAP * marioSprite;
	ALLEGRO_PATH * path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);

	al_init();
	display = al_create_display(800, 600);
	queue = al_create_event_queue();

	al_install_keyboard();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));


	marioSprite = al_load_bitmap("crumpet-engine/resources/textures/mario-sprite.png");
	assert(marioSprite != NULL);

	float x = 0;

	int width = al_get_display_width(display);
	bool running = true;
	while (running) {
		al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));
		al_draw_bitmap(marioSprite, x += 0.01, 0, 0);
		al_flip_display();


		if (x > width) x = -al_get_bitmap_width(marioSprite);

		ALLEGRO_EVENT event;

		if (!al_is_event_queue_empty(queue)) {
			al_wait_for_event(queue, &event);
			if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
				running = false;
		}
	}

	al_destroy_display(display);
	al_uninstall_keyboard();
	al_destroy_bitmap(marioSprite);

	return 0;
}